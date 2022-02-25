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

void test();
void test1();
double returnOnlyPostitive(double val);
double returnOnlyNegative(double val);
void redAMajor_test();
void opcontrol()
{
  redAMajor_test();
  //test1(); // test function; dead loop
  while (true) {
    pros::lcd::set_text(1, std::to_string(imu.get_heading()));
    pros::lcd::set_text(2, std::to_string(drive_encoder_right.get()));
    pros::lcd::set_text(3, std::to_string(encoder_right.get()));
    int i = 0;
    chassis_odom->getModel()->arcade(masterController->getAnalog(okapi::ControllerAnalog::leftY),
                              masterController->getAnalog(okapi::ControllerAnalog::leftX));

    if (i %20 == 0) {
      masterController->setText(1, 1, std::to_string(frontLift_sensor.get()));
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
    if (frontLift_sensor.get()>=5&& frontLift_sensor.get()<=90){
      motor_frontLift->moveVelocity(masterController->getAnalog(okapi::ControllerAnalog::rightY)*100);
    } else if (frontLift_sensor.get()<=5){
      motor_frontLift->moveVelocity(returnOnlyPostitive(masterController->getAnalog(okapi::ControllerAnalog::rightY)*100));
    } else if (frontLift_sensor.get()>=90){
      motor_frontLift->moveVelocity(returnOnlyNegative(masterController->getAnalog(okapi::ControllerAnalog::rightY)*100));
    } else {
      pros::lcd::set_text(4, "Front lift val out of bounds!");
    }

//intakes all time until outtake L1 pressed, reverts back when released.
//Will not move while front lift is not high over set val
    if(frontLift_sensor.get() >= 20) {
      if(conveyer_down.isPressed())
      {
        motor_conveyer->moveVelocity(-0.8 * 600);
      }
      else
      motor_conveyer->moveVelocity(0.8 * 600);
    } else {
      if (conveyer_up.isPressed())
      {
        motor_conveyer->moveVelocity(0.8 * 600);
      }
      else if(conveyer_down.isPressed())
      {
        motor_conveyer->moveVelocity(-0.8 * 600);
      }
      else
      motor_conveyer->moveVelocity(0);
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
        piston_rearFetch.set_value(false);
        pros::delay(100);
        piston_rearClinch.set_value(false);
        isFetch = false;
      } else {
        piston_rearClinch.set_value(true);
        pros::delay(100);
        piston_rearFetch.set_value(true);
        isFetch = true;
      }
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
  turn(180_deg);
  // pros::lcd::set_text(3, std::to_string(imu.get()));
  while(1)
  {
    // pros::lcd::set_text(3, std::to_string(imu.get()));
    pros::delay(10);
  }
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
void redAMajor_test()
{
  // driveLeft->moveVelocity(200);
  // driveRight->moveVelocity(200);
  // pros::delay(900);
  //
  // stop();
  // pros::delay(300);
  // frontIn();
  // pros::delay(300);
  // drive(-35_in);
  // frontOut();
  // drive(-3_in);
  turnTo(170_deg, 0);
  // driveWithLeft(-31.5_in);
  // pros::delay(200);
  // drive(-13_in);
  // backIn();
  // pros::delay(100);
  // drive(7_in);
  //
  // turn(-20_deg, 1);
  // conveyerUp();
  //
  // driveLeft->moveVelocity(70);
  // driveRight->moveVelocity(70);
  // pros::delay(500);
  // // drive(-12_in);
  // // driveLeft->moveVelocity(30);
  // // driveRight->moveVelocity(30);
  // // pros::delay(600);
  stop();
  while(1){}
}
