#include "main.h"
using namespace global;

using namespace okapi::literals;

//units are in degrees
// const int REARLIFT_UP = 0; //set these!
// const int REARLIFT_DOWN = -420;
const int FRONTLIFT_UP = 0;
const int FRONTLIFT_DOWN = 20;
bool isToggled = false;
bool isFetch = false;
bool isClinch = false;
bool isChangedMaxVelocity = false;
void test();
void test1();
double returnOnlyPostitive(double val);
double returnOnlyNegative(double val);
void opcontrol()
{
  // backOut();
  // frontOut();
  test(); // test function; dead loop
  while (true) {


    pros::lcd::set_text(0, "cm:" + std::to_string(distance_top.get()/10.0));
    pros::lcd::set_text(2, std::to_string(getLeftReading()));
    pros::lcd::set_text(3, std::to_string(getRightReading()));
    int i = 0;
    chassis_odom->getModel()->arcade(masterController->getAnalog(okapi::ControllerAnalog::leftY) * 0.90,
                              masterController->getAnalog(okapi::ControllerAnalog::leftX) * 0.65) ;

    if (i %20 == 0) {
      masterController->setText(1, 1, std::to_string(encoder_lift.get()));
    }
//backlift toggle; R1/R2 Assigned
    // if(rearLift_up.changedToPressed()||rearLift_down.changedToPressed())
    // {
    //   if(rearLiftController->getTarget() == REARLIFT_UP) //toggle: double press button
    //   {
    //     rearLiftController->setTarget(REARLIFT_DOWN);
    //   }
    //   else
    //   {
    //     rearLiftController->setTarget(REARLIFT_UP);
    //   }
    // }
//frontlift right analog
  if(liftPlatform.isPressed())
  {
    frontLiftController->setTarget(480);
  }
  else
  {
    if (encoder_lift.get()>=5&& encoder_lift.get()<=90){
      motor_frontLift->moveVoltage(masterController->getAnalog(okapi::ControllerAnalog::rightY)*12000);
    } else if (encoder_lift.get()<=5){
      motor_frontLift->moveVoltage(returnOnlyPostitive(masterController->getAnalog(okapi::ControllerAnalog::rightY)*12000));
    } else if (encoder_lift.get()>=90){
      motor_frontLift->moveVoltage(returnOnlyNegative(masterController->getAnalog(okapi::ControllerAnalog::rightY)*12000));
    } else {
      pros::lcd::set_text(4, "Front lift val out of bounds!");
    }
  }


//intakes all time until outtake L1 pressed, reverts back when released.
//Will not move while front lift is not high over set val

      if (conveyer_up.isPressed())
      {
        motor_conveyer->moveVelocity(0.8 * 600);
      }
      else if(conveyer_down.isPressed())
      {
        motor_conveyer->moveVelocity(-0.8 * 600);
      }
      else
      {
        //old @PARAM (encoder_lift.get()>15 && (distance_top.controllerGet()>300 || encoder_lift.get()<70))
        if(encoder_lift.get()>15)
        {
          motor_conveyer->moveVelocity(0.65 * 600);
        }
        else
          motor_conveyer->moveVelocity(0);
      }

      if(modeChange.changedToPressed())
      {
        chassis_odom->setMaxVelocity(isChangedMaxVelocity ? 160 : 200);
        isChangedMaxVelocity = !isChangedMaxVelocity;
      }
//toggles piston A
    if(piston_toggle.changedToPressed()){
      if(isToggled) //toggle: double press button
      {
        piston_front.set_value(false);
        isToggled = false;
      } else {
        piston_front.set_value(true);
        isToggled = true;
      }
    }

    if(rearFetch.changedToPressed()){
      if(isFetch) //toggle: double press button
      {
        piston_rearFetch.set_value(true);
        pros::delay(200);
        piston_rearClinch.set_value(false);

        isFetch = false;
        isClinch = false;
      } else {

        piston_rearClinch.set_value(true);
        pros::delay(200);
        piston_rearFetch.set_value(false);

        isFetch = true;
        isClinch = true;
      }
    }
    if(balancePlatform.changedToPressed())
    {
        //pros::lcd::set_text(1, "error" + std::to_string(imu.get_pitch()));
      //  pros::lcd::set_text(1, std::to_string(distance_top.get()));
      drive(30_in, 2);
      //balance();
    }

    // if(rearClinch.changedToPressed()){
    //   if(isClinch) //toggle: double press button
    //   {
    //     piston_rearClinch.set_value(false);
    //     isClinch = false;
    //   } else {
    //     piston_rearClinch.set_value(true);
    //     isClinch = true;
    //   }
    // }


    //Absolute position reset for backlift B
    // if(resetByHand.changedToPressed()){
    //   liftRear->moveVelocity(40);
    // }
    // if(resetByHand.changedToReleased()){
    //   liftRear->moveVelocity(0);
    //   rearLiftController->tarePosition();
    // }


    pros::delay(10);
    i++;
  }
}

void test()
{
  //frontIn();
  // backIn();
  // pros::delay(1000)  ;

  // drive(20_in, 0);
  // pros::delay(1000);
  drive(40_in, 0);
  drive(-40_in, 0);
  // drive(-40_in, 0);
  // frontIn();
  // drive(-10_in);
  // liftUp();
  // pros::delay(2000);
  // driveAndApproach(3_in, 1, 3);
  //balance(40_in, 4);
  //driveAndIntake(50_in, 0);
  // frontIn();
  // backIn();dd
  // pros::delay(300);
  // liftUp();
  // pros::delay(3000);
  // drive(60_in, 3);
  // drive(-50_in, 3);
  // drive(30_in, 3);
  // frontLiftController->waitUntilSettled();
  // pros::lcd::set_text(3, std::to_string(imu.get()));
  // while(1)
  // {
  //   pros::lcd::set_text(3, std::to_string(drive_encoder_right.get()));
  //   pros::delay(10);
  // }
  //while(1);
}
double returnOnlyPostitive(double val){
  if (val<=0) {
    return 0;
  } else {
    return val;
  }
}
double returnOnlyNegative(double val){
  if (val>=0) {
    return 0;
  } else {
    return val;
  }
}
void test1()
{
  // chassis_odom->setState({0_in, 0_in, 0_deg});
  // chassis_odom->turnToAngle(90_deg);
  //
  //driveWithLeft(25_in);
  drive(-8_in);
  piston_rearClinch.set_value(true);
  pros::delay(100);
  piston_rearFetch.set_value(true);
  driveWithLeft(29_in);
  pros::delay(100);

  drive(42_in);
  piston_front.set_value(true);
  pros::delay(1000);
}
