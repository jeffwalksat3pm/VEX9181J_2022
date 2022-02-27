#pragma once
#ifndef _MASTER_H_
#define _MASTER_H_

#include "main.h"

namespace global{
  extern okapi::Controller* masterController;
  extern okapi::Controller* partnerController;
  extern okapi::ControllerButton rearFetch;
  extern okapi::ControllerButton rearClinch;
  extern okapi::ControllerButton conveyer_up;
  extern okapi::ControllerButton conveyer_down;
  extern okapi::ControllerButton piston_toggle;
  extern okapi::ControllerButton resetByHand;
  extern okapi::ControllerButton liftPlatform;
  extern okapi::ControllerButton modeChange;
  extern void configure_master();
}

#endif
