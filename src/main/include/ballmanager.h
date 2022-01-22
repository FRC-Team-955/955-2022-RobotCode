#ifndef BALLMANAGER
#define BALLMANAGER
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <frc/DigitalInput.h>
using namespace frc;
#include "settings.h"
#include <iostream>
#include "hopper.h"
#include "breakbeam.h"
#include "colorsensor.h"

class BallManager {
public:
  BallManager() {}
  int GetBallColor();
  void ShootBalls();
  


private:
  DigitalInput limit_switch_top{SensorConst::limit_switch_top_port};
  DigitalInput limit_switch_bottom{SensorConst::limit_switch_bottom_port};
  TalonSRX hopper_motor{1};
  Solenoid solenoid0{PneumaticsModuleType::CTREPCM , 0};
};
#endif