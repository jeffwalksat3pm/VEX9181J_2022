#pragma once
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "main.h"
namespace global{

  extern okapi::ChassisScales scale_chassis;
  extern okapi::ChassisScales scale_tracking;

  extern okapi::AbstractMotor::gearset gearset_chassis;
  extern okapi::AbstractMotor::gearset gearset_lift;
  extern okapi::AbstractMotor::gearset gearset_conveyer;
  extern const double circumference;
  extern const double circumference_intergrated;
}
#endif
