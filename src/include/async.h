#pragma once
#ifndef _ASYNC_H_
#define _ASYNC_H_

#include "main.h"

using namespace okapi;
using namespace pros;
namespace global{
  extern bool isDriveComplete();
  extern double getEncoderReading();
  extern void waitUntilDriveComplete();
  extern void waitUntilTravel(QLength distance);
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
