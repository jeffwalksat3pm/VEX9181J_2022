#include "main.h"
using namespace global;
using namespace okapi::literals;

void redAMinor();
void AMajor();
void BMajor();
void BMajorPlus();
void BMajorCore();
void skills();

void autonomous()
{
  // AMajor();
  // redAMinor();

  // BMajor();
  // BMajorPlus();

  skills();

  while(1){
    pros::delay(100);
  }

  }

  void skills(){
    drive(-6_in);
    pros::delay(200);
    backIn();
    pros::delay(300);
    driveWithLeft(15_in);
    pros::delay(300);
    turnTo(95_deg,1);
    // driveAndIntake(50_in, 1);
    driveLeft->moveVelocity(200);
    driveRight->moveVelocity(200);
    pros::delay(750);
    stop();
    pros::delay(700);
    frontIn();
    drive(30_in,2);
    liftUp();
    turnTo(180_deg,1);
    conveyerUp();
    drive(33_in,3);
    turnTo(90_deg,0);
    backOut();
    driveAndApproach(1_in, 1);
    frontOut();
  }


  void AMajor(){
    motor_frontLift->moveVelocity(-20);
    driveLeft->moveVelocity(195);
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

  void BMajorCore(){
    motor_frontLift->moveVelocity(-20);
    driveLeft->moveVelocity(200);
    driveRight->moveVelocity(200);
    pros::delay(690);
    stop();
    pros::delay(800);
    frontIn();
    pros::delay(100);
    drive(-19_in, 3);
    pros::delay(100);
    turnTo(293_deg,0);
    pros::delay(200);
    frontOut();
    pros::delay(100);
    driveLeft->moveVelocity(-40);
    driveRight->moveVelocity(-40);
    pros::delay(1400);
    stop();
    pros::delay(500);
    backIn();
    pros::delay(200);
    liftIntake();
    conveyerUp();
    pros::delay(200);
    drive(7_in,1);
    turnTo(5_deg, 1);
    stop();
    // drive(25_in,1);
    driveLeft->moveVelocity(40);
    driveRight->moveVelocity(40);
    pros::delay(2500);
  }

  void BMajor(){
    BMajorCore();
    drive(-15_in,1);
    backOut();
    drive(5_in);
  }

  void BMajorPlus(){
    BMajorCore();
    turnTo(90_deg,1);
    drive(8_in,1);
    turnTo(230_deg,0);
  }
