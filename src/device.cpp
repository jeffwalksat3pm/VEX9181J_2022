#include "main.h"

using namespace okapi::literals;
#define DEG okapi::AbstractMotor::encoderUnits::degrees

namespace global{
  okapi::Motor * motor_topLeft = new okapi::Motor(8, 1, gearset_chassis, DEG);
  okapi::Motor * motor_bottomLeft = new okapi::Motor(5, 1, gearset_chassis, DEG);
  okapi::Motor * motor_topRight = new okapi::Motor(2, 0, gearset_chassis, DEG);
  okapi::Motor * motor_bottomRight = new okapi::Motor(7, 0, gearset_chassis, DEG);
  okapi::Motor * motor_midLeft = new okapi::Motor(4, 0, gearset_chassis, DEG);
  okapi::Motor * motor_midRight = new okapi::Motor(3, 1, gearset_chassis, DEG);

  // okapi::Motor * motor_rearLiftLeft = new okapi::Motor(2, 0, gearset_lift, DEG);
  // okapi::Motor * motor_rearLiftRight = new okapi::Motor(4, 1, gearset_lift, DEG);
  okapi::Motor * motor_frontLift = new okapi::Motor(20, 1, gearset_lift, DEG);
  okapi::Motor * motor_conveyer = new okapi::Motor(19, 1, gearset_conveyer, DEG);
  okapi::MotorGroup * driveRight = new okapi::MotorGroup({*motor_topRight, *motor_midRight, *motor_bottomRight});
  okapi::MotorGroup * driveLeft = new okapi::MotorGroup({*motor_topLeft, *motor_midLeft, *motor_bottomLeft});

  okapi::IntegratedEncoder drive_encoder_left(*motor_bottomLeft);
  okapi::IntegratedEncoder drive_encoder_right(*motor_bottomRight);
  //okapi::MotorGroup * liftRear = new okapi::MotorGroup({*motor_rearLiftLeft, *motor_rearLiftRight});
  okapi::ADIEncoder encoder_left({6, 5, 6}, false);
  okapi::ADIEncoder encoder_right({6, 1, 2}, false);
  okapi::ADIEncoder encoder_middle({6, 3, 4}, false);
  okapi::ADIButton limit_back('Z');
  //okapi::DistanceSensor distance_back = okapi::DistanceSensor(8);
  okapi::RotationSensor encoder_lift = okapi::RotationSensor(18);

  pros::IMU imu(9);
  pros::ADIDigitalOut piston_front('A');
  pros::ADIDigitalOut piston_rearFetch('B');
  pros::ADIDigitalOut piston_rearClinch({6, 'H'}, false);

  void configure_device()
  {
    imu.reset();
    while(imu.is_calibrating())
    {
      pros::delay(50);
    }
    // motor_rearLiftLeft->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    // motor_rearLiftRight->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    motor_frontLift->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  }
}
