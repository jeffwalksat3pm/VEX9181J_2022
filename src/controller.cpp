#include "main.h"

using namespace okapi::literals;
namespace global{
  std::shared_ptr<okapi::OdomChassisController> chassis_odom;
  std::shared_ptr<okapi::IterativePosPIDController> leftDriveController;
  std::shared_ptr<okapi::IterativePosPIDController> rightDriveController;
  std::shared_ptr<okapi::IterativePosPIDController> straightDriveController;

  std::shared_ptr<okapi::IterativePosPIDController> turnController;

  std::shared_ptr<okapi::AsyncPositionController<double, double>> rearLiftController;
  std::shared_ptr<okapi::AsyncPositionController<double, double>> frontLiftController;
  std::shared_ptr<okapi::AsyncPositionController<double, double>> conveyerController;

  std::shared_ptr<okapi::IterativePosPIDController> balanceController;
  std::shared_ptr<okapi::IterativePosPIDController> balanceDriveController;
//0.000480, -0.0000000, -0.000135
okapi::IterativePosPIDController::Gains right_gain[4] = {{0.000370, -0.000060, -0.00012}, {0.001040, -0.000005, -0.000050}, {0.001300, -0.000010, -0.000020}, {0.000370, -0.000010, -0.00020}};
okapi::IterativePosPIDController::Gains left_gain[4] = {{0.000370, -0.000060, -0.00012}, {0.001040, -0.000005, -0.000050}, {0.001300, -0.000010, -0.000020}, {0.000370, -0.000010, -0.00020}};
  // okapi::IterativePosPIDController::Gains distance_gain[4] = {{0.00050, -0.000060, -0.000090}, {0.001040, -0.000005, -0.000050}, {0.001300, -0.000010, -0.000020}, {0.000370, -0.000010, -0.00020}};
  // okapi::IterativePosPIDController::Gains turn_gain = {0.0, 0.0, 0.0};
  okapi::IterativePosPIDController::Gains turn_gain = {0.0055, 0.0002, -0.00016};
  // okapi::IterativePosPIDController::Gains angle_gain = {0.000001, 0.0, 0.0000001};
   okapi::IterativePosPIDController::Gains angle_gain = {0.000003, 0.0000001, 0.0000005};

  void build_chassis()
  {
    chassis_odom  = okapi::ChassisControllerBuilder()
    //.withMotors({*motor_topLeft, *motor_midLeft, *motor_bottomLeft}, {*motor_topRight, *motor_midRight, *motor_bottomRight})
    .withMotors(*driveLeft, *driveRight)
    .withDimensions(gearset_chassis, scale_chassis)
    .withGains(left_gain[0], turn_gain, angle_gain)
    .withOdometry(scale_tracking, okapi::StateMode::CARTESIAN)
    //.withSensors(encoder_left, encoder_right, encoder_middle)
    //.withSensors( okapi::ADIEncoder({6, 5, 6}, false), okapi::ADIEncoder({6, 1,2 }, false))
    .withMaxVoltage(12000)
    .withMaxVelocity(200)
    .withDerivativeFilters(
        std::make_unique<okapi::AverageFilter<3>>(), // Distance controller filter
        std::make_unique<okapi::AverageFilter<3>>(), // Turn controller filter
        std::make_unique<okapi::AverageFilter<3>>()  // Angle controller filter
    )
    .withClosedLoopControllerTimeUtil()
    .buildOdometry();

  }
  void build_pid()
  {
    const double drivingKp = 0.0;
    const double drivingKi = -0.0;
    const double drivingKd = -0.0;
    leftDriveController = std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(drivingKp, drivingKi, drivingKd));
    rightDriveController = std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(drivingKp, drivingKi, drivingKd));
    configureDrive(0);
    leftDriveController->setControllerSetTargetLimits(0.9, -0.85);
    rightDriveController->setControllerSetTargetLimits(0.8925, -0.837);

    // balanceDriveController = std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(drivingKp, drivingKi, drivingKd));
    // balanceDriveController->setControllerSetTargetLimits(0.6, 0.6);

    straightDriveController = std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(drivingKp, drivingKi, drivingKd));
    straightDriveController->setGains(angle_gain);
    // balanceController = std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(0.1, 0.0001, 0.001));
    // balanceController->setControllerSetTargetLimits(0.9, 0.9);
    turnController =
        std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(drivingKp, drivingKi, drivingKd));
    turnController->setGains(turn_gain);
    turnController->setControllerSetTargetLimits(1.0, -1.0);
    // Set output limits for controllers
    turnController->setOutputLimits(1.0, -1.0);

  }
  void build_component()
  {
    frontLiftController = okapi::AsyncPosControllerBuilder().withMotor(*motor_frontLift).withSensor(std::make_shared<okapi::RotationSensor>(encoder_lift)).withMaxVelocity(100).withGearset(gearset_lift).build();
    conveyerController = okapi::AsyncPosControllerBuilder().withMotor(*motor_conveyer).withMaxVelocity(600).withGearset(gearset_conveyer).build();
  }
}
