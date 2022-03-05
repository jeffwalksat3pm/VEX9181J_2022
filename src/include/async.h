#pragma once
#ifndef _ASYNC_H_
#define _ASYNC_H_

#include "main.h"

using namespace okapi;
using namespace pros;
namespace global{
  extern bool drive_complete;
  extern Task *drive_task;
  extern unsigned int withMogos;
  extern QLength target_distance;
  extern bool isDriveComplete();

  extern void waitUntilDriveComplete();
  extern void waitUntilTravel(QLength distance);
  extern void waitUntilReach(QLength distance, bool top);
  extern void drive_async(void* param);
  extern void turn_async(void* param);
  extern void turn_to_async(void* param);
  extern void drive_approach(void *param);

  extern void asyncDrive(QLength distance, unsigned int drive_options);
  extern void asyncTurn(QAngle angle);
  extern void asyncTurnTo(QAngle angle, bool clockwise);
  extern void asyncApproach(QLength gap, bool top, unsigned int drive_options);


}
#endif
