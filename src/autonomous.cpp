#include "main.h"
using namespace global;
using namespace okapi::literals;

void redAMinor();
void AMajor();
void BMajor();
void BMajorPlus();

void autonomous()
{
  // AMajor();
  // redAMinor();

  BMajor();
  // BMajorPlus();
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

  void redAMinor(){
    drive(-6_in);
    pros::delay(370);
    backIn();
    liftIntake();
    pros::delay(300);
    conveyerUp();
    turn(20_deg);
    conveyerDown();
    pros::delay(300);
    conveyerUp();
    driveWithLeft(32_in);
    pros::delay(400);
    driveLeft->moveVelocity(48);
    driveRight->moveVelocity(51);
    pros::delay(3100);
    liftDown();
    pros::delay(700);
    motor_frontLift->moveVelocity(0);
    motor_conveyer->moveVelocity(0);
    frontIn();
    pros::delay(500);
    stop();
    pros::delay(200);
    driveLeft->moveVelocity(-170);
    driveRight->moveVelocity(-200);
    pros::delay(1000);
    stop();
    pros::delay(300);
    frontOut();
    pros::delay(300);
    liftIntake();
    conveyerUp();
    drive(-9_in);
    backOut();
    drive(5_in);
  }

  void BMajor(){
    driveLeft->moveVelocity(200);
    driveRight->moveVelocity(200);
    pros::delay(670);

    stop();
    pros::delay(800);
    frontIn();
    pros::delay(100);
    drive(-25_in, 1);
    pros::delay(100);
    turn(-72_deg);

    driveLeft->moveVelocity(-40);
    driveRight->moveVelocity(-40);
    pros::delay(900);
    stop();
    pros::delay(400);
    backIn();
    pros::delay(100);

    liftIntake();
    conveyerUp();

    turn(72_deg);

    pros::delay(3000);
    frontOut();
    backOut();
  }
