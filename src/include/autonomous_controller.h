  #pragma once
#ifndef _AUTONOMOUS_CONTROLLER_H_
#define _AUTONOMOUS_CONTROLLER_H_

#include "main.h"
namespace global{

  extern double getLeftReading();
  extern double getRightReading();

  extern void configureDrive(unsigned int withMogo = 0);
  //front clinch intakes
  extern void frontIn();
  //front clinch outtakes
  extern void frontOut();
  //back clinch intakes
  extern void backIn();
  //back clinch outtakes
  extern void backOut();
  //perform a set of programmed move to init
  extern void startup();
  //stop chassis drive
  extern void stop();
  //conveyer intakes
  extern void conveyerUp();
  //conveyer stop intake
  extern void conveyerDown();
  //arm raises
  extern void liftUp();
  //arm raises for conveyer intakes
  extern void liftIntake();
  //arms reset
  extern void liftDown();

  //drives for a target distance using PID.
  //@PARAM okapi::QLength targetDistance - Smart Unit Length
  extern void drive(okapi::QLength targetDistance);
  //drive(okapi::QLength targetDistance); using different PID profiles on choice.
  //@PARAM okapi::QLength targetDistance - Smart Unit Length | @PARAM unsigned int withMogo - profile ID
  extern void drive(okapi::QLength targetDistance, unsigned int withMogo);

  //drive(okapi::QLength targetDistance, unsigned int withMogo) for a target distance and then intakes front mogo.
  //@PARAM okapi::QLength targetDistance - Smart Unit Length | @PARAM unsigned int withMogo - profile ID
  extern void driveAndIntake(okapi::QLength targetDistance, unsigned int withMogo);
  //drives using PID and a selected distance sensor and targets a certain distance between the sensor and the object.
  //@PARAM okapi::QLength targetDistance - Smart Unit Length | @PARAM bool top - true for top sensor, false for bottom sensor
  extern void driveAndApproach(okapi::QLength targetDistance, bool top);
  //driveAndApproach(okapi::QLength targetDistance, bool top) using different PID profiles.
  //@PARAM okapi::QLength targetDistance - Smart Unit Length | @PARAM bool top - true for top sensor, false for bottom sensor
  extern void driveAndApproach(okapi::QLength targetDistance, bool top, unsigned int withMogo);

  //drives in PID assigning different target length to left and right motors
  extern void driveIndependent(okapi::QLength leftLength, okapi::QLength rightLength);

  //turns on positon to an absolute heading target on IMU.
  //@PARAM okapi::QAngle targetDegrees - absolute target heading | @PARAM bool dir - direction of the turn, true for clockwise, false for counter-clockwise.
  extern void turnTo(okapi::QAngle targetDegrees, bool dir);
  //turns on position to a relative heading target on IMU.
  //@PARAM okapi::QAngle targetDegrees - relative target heading
  extern void turn(okapi::QAngle targetDegrees);

  //balances the robot automatically when parking of the robot on the platform.
  extern void balance();

  //drives with PID only on the left motors to a target.
  //@PARAM okapi::QLength length - target distance for the left motors to move
  extern void driveWithRight(okapi::QLength length);
  //drives with PID only on the right motors to a target.
  //@PARAM okapi::QLength length - target distance for the right motors to move
  extern void driveWithLeft(okapi::QLength length);
}
#endif
