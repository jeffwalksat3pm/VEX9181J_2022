#include "main.h"
using namespace global;
using namespace okapi::literals;

void autonomous()
{

  drive(40_in);
  while(1)
  {
    pros::lcd::set_text(1, std::to_string(encoder_left.get()));
    pros::lcd::set_text(2, std::to_string(encoder_right.get()));
    pros::lcd::set_text(3, std::to_string(encoder_middle.get()));
    pros::delay(30);
  }
  //right side auto
  // piston_front.set_value(false);// clamp
  // drive(48_in);
  // driveRight->moveVoltage(2400);
  // driveLeft->moveVoltage(2400);
  // pros::delay(700);
  // piston_front.set_value(true);// clamp
  // pros::delay(100);
  // drive(-50_in);
  //go to diagonal position of yellow mogo
  // drive(47.5_in);//fwd
  // turn(45_deg,1.0);//turn
  // drive(3_in);//goto mogo
  // piston_front.set_value(true);// clamp
  // pros::delay(100);//wait til clamp clamps
  // //revert back to original pos
  // drive(-17_in);
  // turn(-45_deg,1.0);//turn
  // drive(-40_in);
  // //turn and get the backmogo
  // turn(-90_deg, 1.0);
  // okapi::QLength getBack(distance_back.get() -20);  // get back sensor value by mm and converts into Qlength
  // drive(-getBack); // drive back for QLength
  //
  // //slows down and approach, stops when back limit is pressed
  // // while(!limit_back.isPressed())
  // // {
  // //   driveRight->moveVelocity(-10);
  // //   driveLeft->moveVelocity(-10);
  // //   pros::delay(30);
  // // }
  // driveRight->moveVelocity(-10);
  // driveLeft->moveVelocity(-10);
  // pros::delay(300);
  //
  // //stops and lifts backlift to obtain blue mogo
  // stop();
  //
  // rearLiftController->setTarget(340);
  // rearLiftController->waitUntilSettled();
  // //might be at the platform, drive away
  // drive(10_in);
  // //elevate front lifts
  // // Elevates front lift to make space for the rings to be intaked
  // while (frontLift_sensor.get()<=20){
  //   motor_frontLift->moveVelocity(50);
  // }
  // //score rings to backmogo
  // motor_conveyer->moveVelocity(200);
  // pros::delay(1000);
  // motor_conveyer->moveVelocity(0);

}
