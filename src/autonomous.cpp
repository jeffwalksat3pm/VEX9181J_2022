#include "main.h"
using namespace global;
using namespace okapi::literals;

void redAMinor();
void AMajor();
void BMajor();
void BMajorCore();
void skills();

void autonomous()
{
  // AMajor();
  // redAMinor();

  BMajor();

  // skills();

  while(1){
    pros::delay(100);
  }

  }

  void skills(){
    backOut();
    frontOut();
    pros::delay(300);
    asyncDrive(-6_in,0);
    pros::delay(500);
    backIn();//red1
    waitUntilDriveComplete();
    driveWithLeft(15_in);
    pros::delay(300);
    turnTo(97_deg,1);
    pros::delay(200);
    // driveAndIntake(50_in, 1);
    motor_frontLift->moveVelocity(-20);
    asyncDrive(48_in, 0);
    waitUntilReach(3.5_cm, 0);
    frontIn();
    pros::delay(200);
    waitUntilDriveComplete();
    liftUp();
    conveyerUp();
    drive(33_in,3);//////////////
    conveyerUp();
    turnTo(180_deg,1);/////////////////
    driveLeft->moveVelocity(80);
    driveRight->moveVelocity(80);
    pros::delay(2450);
    stop();
    pros::delay(500);
    asyncDrive(-40_in,3);
    conveyerDown();
    pros::delay(300);
    conveyerUp();
    // drive(45_in,3);
    // drive(-30_in,3);
    waitUntilDriveComplete();
    backOut();//red out

    // pros::delay(20000);
    motor_conveyer->moveVelocity(0);

    drive(5.5_in,3);
    pros::delay(200);
    turnTo(85_deg,0);
    pros::delay(200);
    motor_frontLift->moveVelocity(40);
    driveLeft->moveVelocity(140);
    driveRight->moveVelocity(140);
    pros::delay(800);
    driveLeft->moveVelocity(40);
    driveRight->moveVelocity(40);
    pros::delay(800);
    stop();
    pros::delay(300);
    frontOut();//score yellow1
    pros::delay(200);
    motor_frontLift->moveVelocity(20);
    pros::delay(300);
    asyncDrive(-20_in,0);
    pros::delay(200);
    liftDown();
    waitUntilDriveComplete();
    pros::delay(300);
    turnTo(0_deg, 0);
    asyncDrive(15_in,0);
    waitUntilReach(4_cm, 0);


    frontIn();//red1 again
    pros::delay(200);           ////////////////////////////
    // liftUp();
    waitUntilDriveComplete();
    drive(-23_in, 0);
    liftUp();
    turnTo(92_deg,1);
    pros::delay(400);
    motor_frontLift->moveVelocity(20);
    driveLeft->moveVelocity(55);
    driveRight->moveVelocity(55);
    pros::delay(2300);
    stop();
    frontOut();//score red1
    pros::delay(200);
    motor_frontLift->moveVelocity(20);
    pros::delay(300);
    asyncDrive(-20_in,0);
    pros::delay(200);
    liftDown();
    waitUntilDriveComplete();
    pros::delay(200);
    turnTo(186_deg, 1);
    pros::delay(200);
    drive(-54_in,0);
/////////////
    // driveLeft->moveVelocity(-40);
    // driveRight->moveVelocity(-40);
    // pros::delay(1100);
    // stop();
    backIn();
    pros::delay(200);
    drive(55_in, 2);
    turnTo(270_deg,1);
    // asyncDrive(32_in,1, 0.5);
    // // waitUntilDriveComplete();
    // conveyerDown();
    // stop();
    // pros::delay(500);
    // conveyerUp();
    // turnTo(180_deg, 0);
    // pros::lcd::set_text(6,  std::to_string(imu.get_heading()));
    // pros::delay(200);
    // // asyncDrive(34_in,1, 0.5);
    // // waitUntilReach(10_cm, 0);
    // driveLeft->moveVelocity(55);
    // driveRight->moveVelocity(55);
    // pros::delay(2100);
    // liftDown();
    // pros::delay(600);
    // frontIn();//get big
    // drive(4_in,2);
    // turnTo(270_deg, 1);


    drive(38_in,2);
    drive(-19_in,1); //ass
    liftIntake();
    pros::delay(400);
    turnTo(179_deg,0);
    pros::delay(500);
    conveyerUp();
    driveLeft->moveVelocity(40);
    driveRight->moveVelocity(40);
    pros::delay(2300);
    asyncDrive(-5_in, 1);
    pros::delay(200);
    liftDown();

    waitUntilDriveComplete();
    pros::delay(500);
    driveLeft->moveVelocity(40);
    driveRight->moveVelocity(40);
    conveyerDown();
    pros::delay(2000);
    frontIn();
    //yellow2
    stop();
    pros::delay(500);
    // drive(-19_in, 2);
    // turn(-90_deg);
    // drive(35_in, 2);
    // turn(60_deg);
    // frontOut();
    // drive(3_in, 2);
    // drive(-3_in, 1);
    // pros::delay(300);
    // turn(-60_deg);
    // pros::delay(300);
    // driveLeft->moveVelocity(50);
    // driveRight->moveVelocity(50);
    // pros::delay(1000);
    // frontIn();
    // stop();
    // pros::delay(500);
    // drive(-50_in, 2);
    // asyncTurn(180_deg);
    // liftUp();
    // waitUntilDriveComplete();
    // drive(80_in, 3);
    turn(90_deg);
    liftUp();
    conveyerUp();
    pros::delay(1000);
    drive(60_in, 3);
    pros::delay(500);
    conveyerDown();
    turnTo(0_deg, 1);
    pros::delay(500);
    liftDown();
    driveLeft->moveVelocity(20);
    driveRight->moveVelocity(20);
    pros::delay(400);
    stop();
    pros::delay(1500);
    drive(29_in, 2);
    pros::delay(300);
    frontOut();
    backOut();
  }


  void AMajor(){
    frontOut();
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
    backOut();
    pros::delay(300);
    drive(-4_in);
    // pros::delay(200);
    driveWithLeft(-44_in);
    drive(-9_in);
    backIn();
    conveyerUp();
    liftUp();
    pros::delay(500);
    drive(23_in);
    stop();
    pros::delay(200);
    for(int i = 0; i < 2 ;i++){
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
    drive(3_in,0);
  }

  void redAMinor(){
    frontOut();
    backOut();
    pros::delay(300);
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
    frontOut();
    motor_frontLift->moveVelocity(-20);
    asyncDrive(44.2_in, 1);
    // waitUntilReach(3.6_cm, 0);
    waitUntilTravel(42_in);
    frontIn();
    waitUntilDriveComplete();

    // driveLeft->moveVelocity(200);
    // driveRight->moveVelocity(200);
    // pros::delay(690);
    // stop();
    // pros::delay(450);
    drive(-21.6_in, 1);
    backOut();
    pros::delay(300);
    turnTo(290_deg, 0);
    frontOut();
    pros::delay(100);
    driveLeft->moveVelocity(-40);
    driveRight->moveVelocity(-40);
    pros::delay(1400);
    stop();
    pros::delay(200);
    piston_rearClinch.set_value(true);
    //pros::delay(300
    pros::delay(300);
    piston_rearFetch.set_value(true);
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
