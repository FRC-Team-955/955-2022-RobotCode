#include "intake.h"
using namespace frc;

void Intake::PistonUp() {
  sol1.Set(1);
  sol2.Set(1);
}

void Intake::PistonDown() {
  sol1.Set(0);
  sol2.Set(0);
}

void Intake::RunIntake(float intake_percent) {
  intake_talon.Set(ControlMode::PercentOutput, intake_percent);
  if (intake_talon.GetOutputCurrent() > MechanismConst::kintake_reversal_amps) {
    intake_percent *= -1;
    if (intake_talon.GetOutputCurrent() < MechanismConst::kintake_reversal_amps + 10){
      intake_percent *= 1;
    }
}
}

void Intake::StopIntake() { 
  intake_talon.Set(ControlMode::PercentOutput, 0); 
}
