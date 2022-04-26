#pragma once
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "main.h"
namespace global{

  extern std::shared_ptr<okapi::OdomChassisController> chassis_odom;
  extern std::shared_ptr<okapi::IterativePosPIDController> leftDriveController;
  extern std::shared_ptr<okapi::IterativePosPIDController> rightDriveController;
  extern std::shared_ptr<okapi::IterativePosPIDController> straightDriveController;
  extern std::shared_ptr<okapi::IterativePosPIDController> turnController;
  extern std::shared_ptr<okapi::AsyncPositionController<double, double>> rearLiftController;
  extern std::shared_ptr<okapi::AsyncPositionController<double, double>> frontLiftController;
  extern std::shared_ptr<okapi::AsyncPositionController<double, double>> conveyerController;
  extern std::shared_ptr<okapi::IterativePosPIDController> balanceController;

  extern okapi::IterativePosPIDController::Gains left_gain[];
  extern okapi::IterativePosPIDController::Gains right_gain[];
  extern okapi::IterativePosPIDController::Gains turn_gain;
  extern okapi::IterativePosPIDController::Gains angle_gain;

  extern void build_chassis();
  extern void build_pid();
  extern void build_master();
  extern void build_component();
}
#endif
