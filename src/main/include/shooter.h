#ifndef SHOOTER
#define SHOOTER

#include <iostream>
#include "ctre/Phoenix.h"
#include "frc/Joystick.h"

using namespace frc;

class Shooter {
  Shooter() {}

public:
  float ShootAtVelocity(int velocity);
  void ShootPercentOutput(int percent);

private:
  TalonSRX shooter_talon{1};
};

#endif
