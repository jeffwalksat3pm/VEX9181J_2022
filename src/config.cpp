#include "main.h"

using namespace okapi;
namespace global{
  okapi::AbstractMotor::gearset gearset_chassis = okapi::AbstractMotor::gearset::green;
  okapi::ChassisScales scale_chassis = {{3.25_in, 14.125_in}, imev5GreenTPR};
  //okapi::ChassisScales scale_tracking = {{2.75_in, 8.25_in, 0_in, 2.75_in}, quadEncoderTPR};
  okapi::ChassisScales scale_tracking = {{2.75_in, 8.25_in}, quadEncoderTPR};
  okapi::AbstractMotor::gearset gearset_lift = okapi::AbstractMotor::gearset::red;
  okapi::AbstractMotor::gearset gearset_conveyer = okapi::AbstractMotor::gearset::blue;
}
