#include "main.h"

using namespace okapi;

namespace global{
  void frontIn()
  {
    piston_front.set_value(true);
    pros::delay(200);
  }
  void frontOut()
  {
    piston_front.set_value(false);
    pros::delay(100);
  }
  void backIn()
  {
    piston_rearClinch.set_value(true);
    //pros::delay(300
    pros::delay(500);
    piston_rearFetch.set_value(false);
    pros::delay(100);
  }
  void backOut()
  {
    piston_rearFetch.set_value(true);
    pros::delay(200);
    piston_rearClinch.set_value(false);
    pros::delay(100);
  }
  void liftUp()
  {
    frontLiftController->setTarget(650);
  }

  void liftIntake()
  {
    frontLiftController->setTarget(200);
  }

  void liftDown()
  {
    frontLiftController->setTarget(0);
  }
  void conveyerUp()
  {
    motor_conveyer->moveVelocity(0.95 * 600);
  }
  void conveyerDown()
  {
    motor_conveyer->moveVelocity(0.30 * -600);
  }
  // void startup()
  // {
  //   //have piston released
  //   piston_front.set_value(false);
  //   //expands backlift and resets positions
  //   rearLiftController->setTarget(-345);
  //   rearLiftController->waitUntilSettled();
  //   liftRear->moveVoltage(-5000);
  //   pros::delay(400);
  //   liftRear->moveVoltage(0);
  //   pros::delay(200);
  //   rearLiftController->tarePosition();
  // }
  double getHorizontalReading()
  {
    return tracking_wheel.controllerGet();
  }
  void leftReset()
  {
    drive_encoder_leftBottom.reset();
    drive_encoder_leftMid.reset();
    drive_encoder_leftTop.reset();
  }
  void rightReset()
  {
    drive_encoder_rightBottom.reset();
    drive_encoder_rightMid.reset();
    drive_encoder_rightTop.reset();
  }
  void reset()
  {
    leftReset();
    rightReset();
  }
  double getLeftReading(){
    return (drive_encoder_leftBottom.controllerGet() + drive_encoder_leftMid.controllerGet() + drive_encoder_leftTop.controllerGet()) / 3;
  }
  double getRightReading(){
    return (drive_encoder_rightBottom.controllerGet() + drive_encoder_rightMid.controllerGet() + drive_encoder_rightTop.controllerGet()) / 3;
  }
  void stop()
  {
    // Stop the drivetrain
    driveLeft->controllerSet(0.0);
    driveRight->controllerSet(0.0);
  }

  void configureDrive(unsigned int withMogo)
  {
    leftDriveController->setGains(left_gain[withMogo]);
    rightDriveController->setGains(right_gain[withMogo]);
  }
  void drive(QLength targetDistance)
  {
    // reset();
    leftDriveController->reset();
    rightDriveController->reset();

    double startReading = getEncoderReading();
    double trackingReading = getHorizontalReading();
    // Calculate required amount of degrees to travel
    double cm = targetDistance.convert(centimeter);
    double degrees = (cm / circumference) * 360.0;

    double tune = degrees > 0 ? 1 : 0.98;
    // Set targets
    leftDriveController->setTarget(degrees);
    rightDriveController->setTarget(degrees);

    printf("Target: %fcm\n", cm);

    int timeStart = pros::millis();

    int timeWhenOk = -1;
    while (!leftDriveController->isSettled() && !rightDriveController->isSettled())
    {
      // Get current gyro value
      if (pros::millis() - timeStart > 3000)
      {
        pros::lcd::print(3, "stopped");
        break;
      }
      // Get current positions
      double distanceReading =getEncoderReading() - startReading;
      double leftReading = getLeftReading();
      double rightReading = getRightReading();
      double diffReading = getHorizontalReading() - trackingReading;

      // Get the powers
      double leftPower = leftDriveController->step(distanceReading);
      double rightPower = rightDriveController->step(distanceReading);
      double straightPower = straightDriveController->step(diffReading);
      // Apply powers
      driveLeft->controllerSet(tune * leftPower + straightPower);
      driveRight->controllerSet(tune * rightPower - straightPower);

      double leftCentimeters = (distanceReading / 360.0) * circumference;
      double rightCentimeters = (distanceReading / 360.0) * circumference;

      // double leftError = degrees - leftReading;
      // double rightError = degrees - leftReading;
      double error = degrees - distanceReading;
      bool ok = abs(error) < 10.0;

      if(ok && timeWhenOk == -1) {
        timeWhenOk = pros::millis();
      }
      else if(!ok) {
        timeWhenOk = -1;
      }
      else if(ok && pros::millis() - timeWhenOk > 100) {
        break;
      }

      // Log data
      printf("%fcm -> %fcm | %fcm -> %fcm\n", leftCentimeters, cm, rightCentimeters, cm);
      pros::delay(1);
    }
    // Stop the drives
    stop();
  }
  void drive(QLength targetDistance, unsigned int withMogo)
  {
    configureDrive(withMogo);
    drive(targetDistance);
    configureDrive(0);
  }
  void driveAndIntake(QLength targetDistance, unsigned int withMogo)
  {
    withMogo = withMogo >= 2 ? 1 : withMogo;
    leftDriveController->setGains(left_gain[withMogo]);
    rightDriveController->setGains(right_gain[withMogo]);
    // Reset everything
    //drive_encoder_right.reset();
    //reset();
    leftDriveController->reset();
    rightDriveController->reset();

    double startReading = getEncoderReading();
    // Calculate required amount of degrees to travel
    double cm = targetDistance.convert(centimeter);
    double degrees = (cm / circumference) * 360.0;

    double tune = degrees > 0 ? 1 : 0.98;
    // Set targets
    leftDriveController->setTarget(degrees);
    rightDriveController->setTarget(degrees);

    printf("Target: %fcm\n", cm);

    int timeStart = pros::millis();

    int timeWhenOk = -1;

    int timeArrive = -1;
    bool isIn = 0;
    while (!leftDriveController->isSettled() && !rightDriveController->isSettled())
    {
      // Get current gyro value
      if (pros::millis() - timeStart > 3000)
      {
        pros::lcd::print(3, "stopped");
        break;
      }
      if(timeArrive == -1 && !isIn)
      {
        if(distance_bottom.get() < 30)
        {
          timeArrive = pros::millis();
        }
      }
      else
      {
        if(pros::millis() - timeArrive > 500)
        {
          masterController->setText(1, 1, std::to_string(distance_bottom.get()));
          piston_front.set_value(true);
          frontLiftController->setTarget(80);
          timeArrive = -1;
          isIn = 1;
          leftDriveController->setGains(left_gain[3]);
          rightDriveController->setGains(right_gain[3]);
        }
      }
      // Get current positions
      double distanceReading =getEncoderReading() - startReading;
      double leftReading = getLeftReading();
      double rightReading = getRightReading();
      double diffReading = leftReading - rightReading;

      // Get the powers
      double leftPower = leftDriveController->step(distanceReading);
      double rightPower = rightDriveController->step(distanceReading);
      double straightPower = straightDriveController->step(diffReading);
      // Apply powers
      driveLeft->controllerSet(tune * leftPower + straightPower);
      driveRight->controllerSet(tune * rightPower - straightPower);

      double leftCentimeters = (distanceReading / 360.0) * circumference;
      double rightCentimeters = (distanceReading / 360.0) * circumference;

      // double leftError = degrees - leftReading;
      // double rightError = degrees - leftReading;
      double error = degrees - distanceReading;
      bool ok = abs(error) < 10.0;

      if(ok && timeWhenOk == -1) {
        timeWhenOk = pros::millis();
      }
      else if(!ok) {
        timeWhenOk = -1;
      }
      else if(ok && pros::millis() - timeWhenOk > 100) {
        break;
      }

      // Log data
      printf("%fcm -> %fcm | %fcm -> %fcm\n", leftCentimeters, cm, rightCentimeters, cm);
      pros::delay(1);
    }
    // Stop the drives
    stop();
    leftDriveController->setGains(left_gain[0]);
    rightDriveController->setGains(right_gain[0]);
  }
  void driveAndApproach(QLength targetDistance, bool top)
  {
    pros::Distance * distance_sensor = &(top ? distance_top : distance_bottom);
    // Reset everything
    //drive_encoder_right.reset();
    // reset();
    leftDriveController->reset();
    rightDriveController->reset();
    double startReading = getEncoderReading();
    // Calculate required amount of degrees to travel
    double cm = distance_sensor->get()/10.0 - double(targetDistance.convert(centimeter));
    pros::lcd::set_text(3, std::to_string(distance_sensor->get()/10.0 - double(targetDistance.convert(centimeter))));
    double degrees = (cm / circumference) * 360.0;

    double tune = degrees > 0 ? 1 : 0.98;
    // Set targets
    leftDriveController->setTarget(degrees);
    rightDriveController->setTarget(degrees);

    printf("Target: %fcm\n", cm);

    int timeStart = pros::millis();

    int timeWhenOk = -1;
    while (!leftDriveController->isSettled() && !rightDriveController->isSettled())
    {
      // Get current gyro value
      if (pros::millis() - timeStart > 3000)
      {
        pros::lcd::print(3, "stopped");
        break;
      }
      // Get current positions
      double distanceReading =getEncoderReading() - startReading;
      double leftReading = getLeftReading();
      double rightReading = getRightReading();
      double diffReading = leftReading - rightReading;

      // Get the powers
      double leftPower = leftDriveController->step(distanceReading);
      double rightPower = rightDriveController->step(distanceReading);
      double straightPower = straightDriveController->step(diffReading);
      // Apply powers
      driveLeft->controllerSet(tune * leftPower + straightPower);
      driveRight->controllerSet(tune * rightPower - straightPower);

      double leftCentimeters = (distanceReading / 360.0) * circumference;
      double rightCentimeters = (distanceReading / 360.0) * circumference;

      // double leftError = degrees - leftReading;
      // double rightError = degrees - leftReading;
      double error = degrees - distanceReading;
      bool ok = abs(error) < 10.0;

      if(ok && timeWhenOk == -1) {
        timeWhenOk = pros::millis();
      }
      else if(!ok) {
        timeWhenOk = -1;
      }
      else if(ok && pros::millis() - timeWhenOk > 100) {
        break;
      }

      // Log data
      printf("%fcm -> %fcm | %fcm -> %fcm\n", leftCentimeters, cm, rightCentimeters, cm);
      pros::delay(1);
    }
    // Stop the drives
    stop();
  }
  void driveAndApproach(QLength targetDistance, bool top, unsigned int withMogo)
  {
    leftDriveController->setGains(left_gain[withMogo]);
    rightDriveController->setGains(right_gain[withMogo]);
    driveAndApproach(targetDistance, top);
    leftDriveController->setGains(left_gain[0]);
    rightDriveController->setGains(right_gain[0]);
  }
  void driveIndependent(QLength leftLength, QLength rightLength) {
    // Reset everything
    // reset();
    leftDriveController->reset();
    rightDriveController->reset();

    // Calculate required amount of degrees to travel
    double cmLeft = leftLength.convert(centimeter);
    double cmRight = rightLength.convert(centimeter);

    double degreesLeft = (cmLeft / circumference_intergrated) * 360.0;
    double degreesRight = (cmRight / circumference_intergrated) * 360.0;
    // Set targets
    leftDriveController->setTarget(degreesLeft);
    rightDriveController->setTarget(degreesRight);

    printf("Target: %fcm %fcm\n", cmLeft, cmRight);

    int timeStart = pros::millis();

    int timeWhenOk = -1;
    while (!leftDriveController->isSettled() && !rightDriveController->isSettled())
    {
      // Get current gyro value
      if (pros::millis() - timeStart > 3000)
      {
        pros::lcd::print(3, "stopped");
        break;
      }
      // Get current positions
      double leftReading = getLeftReading();
      double rightReading = getRightReading();

      double diffReading = leftReading - rightReading;

      // Get the powers
      double leftPower = leftDriveController->step(leftReading);
      double rightPower = rightDriveController->step(rightReading);
      double straightPower = straightDriveController->step(diffReading);

      // Apply powers
      driveLeft->controllerSet(leftPower + straightPower);
      driveRight->controllerSet(rightPower - straightPower);

      double leftCentimeters = (leftReading / 360.0) * circumference_intergrated;
      double rightCentimeters = (rightReading / 360.0) * circumference_intergrated;

      double leftError = degreesLeft - leftReading;
      double rightError = degreesRight - rightReading;

      // bool ok = leftDriveController->isSettled() && rightDriveController->isSettled();

        bool ok = abs(leftError) < 10.0 && abs(rightError);

        if(ok && timeWhenOk == -1) {
          timeWhenOk = pros::millis();
        }
        else if(!ok) {
          timeWhenOk = -1;
        }
        else if(ok && pros::millis() - timeWhenOk > 10) {
          break;
        }
      }
    // Stop the drives
    stop();
  }

  void driveWithLeft(QLength length) {
    // Reset everything
    leftReset();
    leftDriveController->reset();

    // Calculate required amount of degrees to travel
    double cmLeft = length.convert(centimeter);

    double degreesLeft = (cmLeft / circumference_intergrated) * 360.0;
    // Set targets
    leftDriveController->setTarget(degreesLeft);
    printf("Target: %fcm %fcm\n", cmLeft, 0.0);

    int timeStart = pros::millis();

    int timeWhenOk = -1;
    while (true)
    {
      // Get current gyro value
      if (pros::millis() - timeStart > 3000)
      {
        pros::lcd::print(3, "stopped");
        break;
      }
      // Get current positions
      double leftReading = getLeftReading();

      // Get the powers
      double leftPower = leftDriveController->step(leftReading);
      double straightPower = 0.0;

      // Apply powers
      driveLeft->controllerSet(leftPower + straightPower);

      double leftCentimeters = (leftReading / 360.0) * circumference_intergrated;

      double leftError = degreesLeft - leftReading;

      double error = degreesLeft - leftReading;
        bool ok = abs(error) < 10.0;

        if(ok && timeWhenOk == -1) {
          timeWhenOk = pros::millis();
        }
        else if(!ok) {
          timeWhenOk = -1;
        }
        else if(ok && pros::millis() - timeWhenOk > 5) {
          break;
        }

      // Log data
      pros::delay(1);
    }
    // Stop the drives
    stop();
  }
  void driveWithRight(QLength length) {
    // Reset everything
    rightReset();
    rightDriveController->reset();

    // Calculate required amount of degrees to travel
    double cmRight = length.convert(centimeter);

    double degreesRight = (cmRight / circumference_intergrated) * 360.0;
    // Set targets
    rightDriveController->setTarget(degreesRight);
    printf("Target: %fcm %fcm\n", cmRight, 0.0);

    int timeStart = pros::millis();

    int timeWhenOk = -1;
    while (true)
    {
      // Get current gyro value
      if (pros::millis() - timeStart > 3000)
      {
        pros::lcd::print(3, "stopped");
        break;
      }
      // Get current positions
      double rightReading = getRightReading();

      // Get the powers
      double rightPower = rightDriveController->step(rightReading);
      double straightPower = 0.0;

      // Apply powers
      driveRight->controllerSet(rightPower + straightPower);
      double error = degreesRight - rightReading;
      bool ok = abs(error) < 10.0;

      if(ok && timeWhenOk == -1) {
        timeWhenOk = pros::millis();
      }
      else if(!ok) {
        timeWhenOk = -1;
      }
      else if(ok && pros::millis() - timeWhenOk > 5) {
        break;
      }

      // Log data
      pros::delay(1);
    }
    // Stop the drives
    stop();
  }


  void turn(QAngle targetDegrees)
  {
    // Reset everything
    //gyro.reset();
    double startValue = (imu.get_rotation() + imu2.get_rotation()) / 2;
    turnController->reset();

    double degs = targetDegrees.convert(degree);
    turnController->setTarget(degs);

    printf("Target: %fdeg\n", degs);

    int timeStart = pros::millis();
    pros::lcd::print(3, "running");

    int timeWhenOk = -1;
    while (true)
    {
      // Get current gyro value
      double currentValue = ((imu.get_rotation() + imu2.get_rotation()) / 2) - startValue;

      double error = degs - currentValue;

      bool ok = abs(error) < 1.0;
      if(ok && timeWhenOk == -1) {
        timeWhenOk = pros::millis();
      }
      else if(!ok) {
        timeWhenOk = -1;
      }
      else if(ok && pros::millis() - timeWhenOk > 100) {
        break;
      }

      // Get the power for motors
      double power = turnController->step(currentValue);

      // Set the power
      driveLeft->controllerSet(power);
      driveRight->controllerSet(-power);

      // Log data
      printf("%fdeg -> %fdeg\n", currentValue, targetDegrees);

      pros::delay(10); // Run the control loop at 10ms intervals
    }

    // Stop the drives
    stop();
  }
  void balance()
  {
    // Reset everything
    //gyro.reset();
    double startValue = imu.get_pitch();
    turnController->reset();

    turnController->setTarget(std::abs(startValue)/startValue * 10);


    int timeStart = pros::millis();
    pros::lcd::print(3, "running");

    int timeWhenOk = -1;
    while (true)
    {
      // Get current gyro value
      double currentValue = imu.get_pitch();

      double error = 0-currentValue;
      pros::lcd::set_text(1, "error" + std::to_string(error));
      bool ok = abs(error) < 7;
      if(ok && timeWhenOk == -1) {
        timeWhenOk = pros::millis();
      }
      else if(!ok) {
        timeWhenOk = -1;
      }
      else if(ok && pros::millis() - timeWhenOk > 1000 && abs(error) < 3) {
        break;
      }

      // Get the power for motors
      double power = turnController->step(currentValue);

      // Set the power
      driveLeft->controllerSet(-power);
      driveRight->controllerSet(-power);

      // Log data

      pros::delay(10); // Run the control loop at 10ms intervals
    }

    // Stop the drives
    stop();
  }
  void turnTo(QAngle targetDegrees, bool dir = 1)
  {
    double startValue = imu.get_heading();
    double degs = targetDegrees.convert(degree);
    double target;
      if(startValue > degs)
      {
        target = (360-startValue+degs);
      }
      else
      {
        target = degs-startValue;
      }
      turn((dir ? target : (target-360) ) * degree);
  }

}
