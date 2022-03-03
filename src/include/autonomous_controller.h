#pragma once
#ifndef _AUTONOMOUS_CONTROLLER_H_
#define _AUTONOMOUS_CONTROLLER_H_

#include "main.h"
namespace global{
  extern void frontIn();
  extern void frontOut();
  extern void backIn();
  extern void backOut();
  extern void startup();
  extern void stop();
  extern void conveyerUp();
  extern void conveyerDown();
  extern void liftUp();
  extern void liftIntake();
  extern void liftDown();
  extern void drive(okapi::QLength targetDistance);
  extern void drive(okapi::QLength targetDistance, unsigned int withMogo);
  extern void driveAndIntake(okapi::QLength targetDistance, unsigned int withMogo);
  extern void driveAndApproach(okapi::QLength targetDistance, bool top);
  extern void driveAndApproach(okapi::QLength targetDistance, bool top, unsigned int withMogo);
  extern void driveIndependent(okapi::QLength leftLength, okapi::QLength rightLength);
  extern void turnTo(okapi::QAngle targetDegrees, bool dir);
  extern void turn(okapi::QAngle targetDegrees);
  extern void driveWithRight(okapi::QLength length);
  extern void driveWithLeft(okapi::QLength length);
}
#endif
