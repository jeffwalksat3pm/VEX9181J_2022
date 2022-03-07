#pragma once
#ifndef _ASYNC_H_
#define _ASYNC_H_

#include "main.h"

using namespace okapi;
using namespace pros;
namespace global{
  //returns the global bool drive_complete
  extern bool isDriveComplete();
  //gets encoder value
  extern double getEncoderReading();
  //delays in a while loop until isDriveComplete(); returns true;
  extern void waitUntilDriveComplete();
  //delays in a while loop until isDriveComplete(); returns true AND the getEncoderReading(); returns an value equal to target
  extern void waitUntilTravel(QLength distance);
  //delays in a while loop until isDriveComplete(); returns true AND the  returns an value equal or lower to target
  extern void waitUntilReach(QLength distance, bool top);

  extern void asyncDrive(QLength distance, unsigned int drive_options);
  extern void asyncTurn(QAngle angle);
  extern void asyncTurnTo(QAngle angle, bool clockwise);
  extern void asyncApproach(QLength gap, bool top, unsigned int drive_options);
  extern void update_encoder(void* param);
  extern void setEncoderAsync();
  extern void asyncDrive(QLength distance, unsigned int drive_options, double vel_multiplier);

}
#endif
