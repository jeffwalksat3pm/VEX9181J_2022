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

  okapi::IterativePosPIDController::Gains distance_gain[3] = {{0.000680, -0.000040, -0.000130}, {0.000680, -0.000040, -0.000130}, {0.000680, -0.000040, -0.000130} };
  okapi::IterativePosPIDController::Gains turn_gain = {0.007500, 0.001500, 0.000015};
  okapi::IterativePosPIDController::Gains angle_gain = {0.000001, 0.0, 0.0000001};

  void build_chassis()
  {
    chassis_odom  = okapi::ChassisControllerBuilder()
    //.withMotors({*motor_topLeft, *motor_midLeft, *motor_bottomLeft}, {*motor_topRight, *motor_midRight, *motor_bottomRight})
    .withMotors(*driveLeft, *driveRight)
    .withDimensions(gearset_chassis, scale_chassis)
    .withGains(distance_gain[0], turn_gain, angle_gain)
    .withOdometry(scale_tracking, okapi::StateMode::CARTESIAN)
    //.withSensors(encoder_left, encoder_right, encoder_middle)
    .withSensors( okapi::ADIEncoder({6, 5, 6}, false), okapi::ADIEncoder({6, 1,2 }, false))
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
    // const double drivingKp = 0.001040;
    // const double drivingKi = -0.000070;
    // const double drivingKd = -0.000230;
    const double drivingKp = 0.000680;
    const double drivingKi = -0.000040;
    const double drivingKd = -0.000130;
    leftDriveController = std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(drivingKp, drivingKi, drivingKd));
    rightDriveController = std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(drivingKp, drivingKi, drivingKd));
    //straightDriveController = std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(0.0001, 0.0, 0.00001));
    //straightDriveController = std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(0.000065, 0.0, 0.000008));
    straightDriveController = std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(0.000001, 0.0, 0.0000001));
    turnController =
        //std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(0.010000, 0.002080, 0.000020));
        std::make_shared<okapi::IterativePosPIDController>(okapi::IterativeControllerFactory::posPID(0.007500, 0.001500, 0.000015));
    // Set output limits for controllers
    leftDriveController->setOutputLimits(1.0, -1.0);
    rightDriveController->setOutputLimits(1.0, -1.0);
    turnController->setOutputLimits(1.0, -1.0);
  }
  void build_component()
  {
    //rearLiftController = okapi::AsyncPosControllerBuilder().withMotor(*motor_rear).withMaxVelocity(100).withGearset(gearset_lift).build();
    frontLiftController = okapi::AsyncPosControllerBuilder().withMotor(*motor_frontLift).withMaxVelocity(100).withGearset(gearset_lift).build();
    conveyerController = okapi::AsyncPosControllerBuilder().withMotor(*motor_conveyer).withMaxVelocity(600).withGearset(gearset_conveyer).build();
  }
}
