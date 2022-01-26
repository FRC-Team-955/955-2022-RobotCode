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
#include "shooter.h"

class BallManager {
public:
  BallManager() {}
  std::string GetHopperState(int position);
  void Shoot();
  bool MoveIndex(int start, int end);
  


private:
  std::string position[2];//position[0] = color of position 1 position[1] = color of position 2
  position[0] = "NULL";
  position[1] = "NULL";
  std::string inbetween;
};
#endif