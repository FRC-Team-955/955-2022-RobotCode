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
#include "hopper.h"

class BallManager {
public:
  BallManager() {}
  std::string GetHopperState(int position);
  void Shoot();
  bool MoveIndex(int start, int end);
  


private:
  std::string ball[2];//ball[0] = color of position 1 ball[1] = color of position 2
  ball[0] = "NULL";
  ball[1] = "NULL";
  
  TalonSRX hopper_motor{1};
  Solenoid solenoid0{PneumaticsModuleType::CTREPCM , 0};
};
#endif