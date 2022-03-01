#include "main.h"
namespace global{
  okapi::Controller* masterController = new okapi::Controller();
  okapi::Controller* partnerController = new okapi::Controller(okapi::ControllerId::partner);
  okapi::ControllerButton rearClinch(okapi::ControllerDigital::L2);
  okapi::ControllerButton rearFetch(okapi::ControllerDigital::L1);
  okapi::ControllerButton conveyer_up(okapi::ControllerDigital::R2);
  okapi::ControllerButton conveyer_down(okapi::ControllerDigital::R1);
  okapi::ControllerButton piston_toggle(okapi::ControllerDigital::A);
  okapi::ControllerButton resetByHand(okapi::ControllerDigital::B);
  okapi::ControllerButton liftPlatform(okapi::ControllerDigital::X);
  okapi::ControllerButton modeChange(okapi::ControllerDigital::Y);
  void configure_master() {

    //masterController = new okapi::Controller();
    //partnerController = new okapi::Controller(okapi::ControllerId::partner);

  }
}
