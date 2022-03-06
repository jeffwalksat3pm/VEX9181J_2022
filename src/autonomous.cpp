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
    asyncDrive(-8_in,0);
    pros::delay(400);
    backIn();//red1
    waitUntilDriveComplete();
    driveWithLeft(15_in);
    pros::delay(300);
    turnTo(100_deg,1);
    // driveAndIntake(50_in, 1);
    motor_frontLift->moveVelocity(-20);
    asyncDrive(44_in, 0);
    waitUntilReach(4.3_cm, 0);
    frontIn();
    pros::delay(300);
    liftUp();
    turnTo(130_deg,1);//turn to platform
    conveyerUp();

    driveAndApproach(7_in,1);  //approach platform
    turnTo(90_deg,0); //align mogo
    pros::delay(200);
    frontOut();//score yellow1
    drive(-5_in,3);
    liftDown();
    backOut(); //red1 release
    drive(5_in,0);
    turnTo(270_deg, 0);
    pros::delay(200);
    asyncDrive(15_in, 0);
    waitUntilReach(3_cm, 0);
    frontIn();//red1 again

    pros::delay(200);
    liftUp();
    turnTo(90_deg,1);
    driveAndApproach(3_in,1);
    frontOut();//score red1
    /* part 2
    drive(-4_in,0);
    liftDown();
    turnTo(180_deg,1);
    driveLeft->moveVelocity(-200);
    driveRight->moveVelocity(-200);
    pros::delay(750);
    stop();
    pros::delay(700);
    backIn();   //blue1
    liftIntake();
    conveyerUp();
    drive(60_in,1);
    turnTo(70_deg,0);
    driveLeft->moveVelocity(60);
    driveRight->moveVelocity(60);
    pros::delay(500);
    stop();
    pros::delay(400);
    frontIn();//blue2
    pros::delay(200);
    liftUp();
    pros::delay(400);
    drive(-20_in,3);
    turnTo(310_deg,0);




    */
  }


  void AMajor(){
    motor_frontLift->moveVelocity(-20);
    driveLeft->moveVelocity(195);
    driveRight->moveVelocity(200);
    pros::delay(750);

    stop();
    pros::delay(670);
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
    for(int i = 0; i<3;i++){
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
    driveLeft->moveVelocity(-80);
    driveRight->moveVelocity(-80);
    pros::delay(370);
    conveyerUp();
    pros::delay(300);
    stop();
    pros::delay(200);
    backOut();
    driveLeft->moveVelocity(80);
    driveRight->moveVelocity(80);
    pros::delay(670);
    stop();
    pros::delay(200);
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
    asyncDrive(44_in, 0);
    waitUntilReach(4.3_cm, 0);
    frontIn();


    // driveLeft->moveVelocity(200);
    // driveRight->moveVelocity(200);
    // pros::delay(690);
    // stop();
    // pros::delay(450);
    drive(-21.6_in, 1);
    turnTo(290_deg, 0);
    frontOut();
    pros::delay(100);
    driveLeft->moveVelocity(-40);
    driveRight->moveVelocity(-40);
    pros::delay(1400);
    stop();
    pros::delay(500);
    backIn();
    pros::delay(200);
    asyncDrive(7_in, 2);
    liftIntake();
    conveyerUp();
    waitUntilDriveComplete();
    turnTo(5_deg, 1);
    stop();
    // drive(25_in,1);
    driveLeft->moveVelocity(40);
    driveRight->moveVelocity(40);
    pros::delay(2500);
  }

  void BMajor(){
    BMajorCore();
    driveLeft->moveVelocity(-40);
    driveRight->moveVelocity(-40);
    pros::delay(1400);
    stop();
    backOut();
    drive(5_in);
  }

  void BMajorPlus(){
    BMajorCore();
    turnTo(90_deg,1);
    drive(8_in,1);
    turnTo(230_deg,0);
  }
