#ifndef INTAKE
#define INTAKE
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include "settings.h"

using namespace frc;

class Intake {
public:
  Intake() {
    intake_talon.TalonSRX::ConfigPeakCurrentLimit(40);
    intake_talon.TalonSRX::EnableCurrentLimit(true);
  }

  void PistonUp();
  void PistonDown();
  void RunIntake(float intake_percent);
  void StopIntake();

private:
  Joystick joy1{1};
  TalonSRX intake_talon{2};
  Solenoid sol1{PneumaticsModuleType::CTREPCM, 0};
  Solenoid sol2{PneumaticsModuleType::CTREPCM, 1};
};

#endif