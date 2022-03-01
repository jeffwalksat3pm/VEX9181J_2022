#include "main.h"
using namespace global;
using namespace okapi::literals;

void AMinor();
void AMajor();

void autonomous()
{
  // AMajor();
  AMinor();
  }

  void AMajor(){
    driveLeft->moveVelocity(192);
    driveRight->moveVelocity(200);
    pros::delay(750);

    stop();
    pros::delay(750);
    frontIn();
    pros::delay(100);

    drive(-32_in);
    frontOut();
    drive(-4_in);
    // pros::delay(200);
    driveWithLeft(-44_in);
    drive(-5_in);
    backIn();
    conveyerUp();
    liftUp();
    pros::delay(500);
    drive(23_in);
    stop();
    pros::delay(200);
    while(1){
      conveyerDown();
      driveLeft->moveVelocity(-80);
      driveRight->moveVelocity(-80);
      pros::delay(370);
      conveyerUp();
      pros::delay(300);
      stop();
      pros::delay(200);
      driveLeft->moveVelocity(80);
      driveRight->moveVelocity(80);
      pros::delay(670);
      stop();
      pros::delay(200);
    }
  }

  void AMinor(){
    drive(-6_in);
    pros::delay(370);
    backIn();
    liftUp();
    pros::delay(300);
    conveyerUp();
    turn(20_deg);
    conveyerDown();
    pros::delay(500);
    conveyerUp();
    driveWithLeft(31_in);
    pros::delay(400);
    driveLeft->moveVelocity(96);
    driveRight->moveVelocity(100);
    pros::delay(1500);
    drive(-5_in);
    driveLeft->moveVelocity(96);
    driveRight->moveVelocity(100);
    pros::delay(1100);
    motor_conveyer->moveVelocity(0);
    stop();
    motor_frontLift->moveVelocity(-20);
    pros::delay(400);
    motor_frontLift->moveVelocity(0);
    driveLeft->moveVelocity(48);
    driveRight->moveVelocity(50);
    pros::delay(800);
    frontIn();
    pros::delay(500);
    stop();
    pros::delay(200);
    driveLeft->moveVelocity(-192);
    driveRight->moveVelocity(-200);
    pros::delay(900);
    stop();
    pros::delay(300);
    frontOut();
    pros::delay(300);
    liftUp();
    conveyerUp();
    drive(-7_in);
    backOut();
    drive(3_in);
  }
