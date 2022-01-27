#ifndef SHOOTER
#define SHOOTER

#include <iostream>
#include "ctre/Phoenix.h"
#include "frc/Joystick.h"
#include "settings.h"

using namespace frc;

class Shooter {
  Shooter() {}

public:
  float ShootAtVelocity(int velocity);
  void ShootPercentOutput(int percent);

private:
  TalonSRX shooter_talon{MechanismConst::kshooter_talon_port};
};

#endif
