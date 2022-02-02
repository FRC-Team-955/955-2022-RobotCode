#ifndef SHOOTER
#define SHOOTER

#include <iostream>
#include "ctre/Phoenix.h"
#include "frc/Joystick.h"
#include "settings.h"
#include <frc/shuffleboard/Shuffleboard.h>

using namespace frc;

class Shooter {
  Shooter() {}

public:
  float ShootAtVelocity(int velocity);
  void ShootPercentOutput(int percent);
  void ShooterAmp(int amp);
void ShooterVelocity(int velocity);

  void DisplayShooterInfo();

private:
  TalonSRX shooter_talon{MechanismConst::kshooter_talon_port};
};

#endif
