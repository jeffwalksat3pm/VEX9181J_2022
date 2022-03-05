#pragma once
#ifndef _DEVICE_H_
#define _DEVICE_H_

#include "main.h"

namespace global{
// OKAPI
// Drivetrain Motors
  extern okapi::Motor * motor_topLeft;
  extern okapi::Motor * motor_topRight;
  extern okapi::Motor * motor_bottomRight;
  extern okapi::Motor * motor_bottomLeft;
  extern okapi::Motor * motor_midLeft;
  extern okapi::Motor * motor_midRight;

// Subsystem Motors
  // extern okapi::Motor * motor_rearLiftLeft;
  // extern okapi::Motor * motor_rearLiftRight;
  extern okapi::Motor * motor_frontLift;
  extern okapi::Motor * motor_conveyer;
// Motor Groups
  extern okapi::MotorGroup * driveLeft;
  extern okapi::MotorGroup * driveRight;

  extern okapi::IntegratedEncoder drive_encoder_left;
  extern okapi::IntegratedEncoder drive_encoder_right;
  extern okapi::MotorGroup * liftRear;
// Odometry Sensors(Triport)
  extern okapi::ADIEncoder encoder_left;
  extern okapi::ADIEncoder encoder_right;
  extern okapi::ADIEncoder encoder_middle;
  extern okapi::RotationSensor encoder_lift;
// Other Triport Sensors
  extern okapi::ADIButton limit_back;
  extern pros::Distance distance_top;
  extern pros::Distance distance_bottom;
  extern okapi::RotationSensor frontLift_sensor;
// PROS Sensors
  extern pros::ADIDigitalOut piston_front;
  extern pros::ADIDigitalOut piston_rearFetch;
  extern pros::ADIDigitalOut piston_rearClinch;
  extern pros::IMU imu;

  extern void configure_device();
}

#endif
