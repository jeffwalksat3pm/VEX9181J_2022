#include "main.h"

using namespace okapi::literals;
#define DEG okapi::AbstractMotor::encoderUnits::degrees

namespace global{
  okapi::Motor * motor_topLeft = new okapi::Motor(11, 0, gearset_chassis, DEG); // r
  okapi::Motor * motor_bottomLeft = new okapi::Motor(12, 1, gearset_chassis, DEG); // r
  okapi::Motor * motor_midLeft = new okapi::Motor(13, 1, gearset_chassis, DEG);
  okapi::Motor * motor_topRight = new okapi::Motor(16, 0, gearset_chassis, DEG); // r
  okapi::Motor * motor_bottomRight = new okapi::Motor(14, 1, gearset_chassis, DEG);
  okapi::Motor * motor_midRight = new okapi::Motor(17, 0, gearset_chassis, DEG); // r

  // okapi::Motor * motor_rearLiftLeft = new okapi::Motor(2, 0, gearset_lift, DEG);
  // okapi::Motor * motor_rearLiftRight = new okapi::Motor(4, 1, gearset_lift, DEG);
  okapi::Motor * motor_frontLift = new okapi::Motor(2, 1, gearset_lift, DEG);
  okapi::Motor * motor_conveyer = new okapi::Motor(1, 1, gearset_conveyer, DEG);
  okapi::MotorGroup * driveRight = new okapi::MotorGroup({*motor_topRight, *motor_midRight, *motor_bottomRight});
  okapi::MotorGroup * driveLeft = new okapi::MotorGroup({*motor_topLeft, *motor_midLeft, *motor_bottomLeft});

  okapi::IntegratedEncoder drive_encoder_leftBottom(*motor_bottomLeft);
  okapi::IntegratedEncoder drive_encoder_rightBottom(*motor_bottomRight);
  okapi::IntegratedEncoder drive_encoder_leftMid(*motor_midLeft);
  okapi::IntegratedEncoder drive_encoder_rightMid(*motor_midRight);
  okapi::IntegratedEncoder drive_encoder_leftTop(*motor_topLeft);
  okapi::IntegratedEncoder drive_encoder_rightTop(*motor_topRight);
  //okapi::MotorGroup * liftRear = new okapi::MotorGroup({*motor_rearLiftLeft, *motor_rearLiftRight});

  pros::Distance distance_top = pros::Distance(5);
  pros::Distance distance_bottom = pros::Distance(7);

  //okapi::ADIEncoder encoder_left('', '', false);
  okapi::ADIEncoder encoder_right('E','F', false);
  // okapi::ADIEncoder encoder_middle({6, 3, 4}, false);
  okapi::ADIButton limit_back('Z');
  //okapi::DistanceSensor distance_back = okapi::DistanceSensor(8);
  okapi::RotationSensor encoder_lift = okapi::RotationSensor(3);
  okapi::RotationSensor tracking_wheel = okapi::RotationSensor(18);

  pros::IMU imu(8);
  pros::IMU imu_backup(9);
  //expander port 4
  pros::ADIDigitalOut piston_front({{4, 'H'}});
  pros::ADIDigitalOut piston_rearFetch({{4, 'A'}});
  pros::ADIDigitalOut piston_rearClinch({{4, 'E'}});

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
    distance_top.get();
    distance_bottom.get();
    setEncoderAsync();
  }
}
