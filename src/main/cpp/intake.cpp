#include "intake.h"
#include "units/time.h"
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
    timer.Start();
  }
  if (timer.HasElapsed(units::second_t(MechanismConst::kintake_reversal_time))) {
    intake_percent *= -1;
    timer.Reset();
  }
}

void Intake::StopIntake() { 
  intake_talon.Set(ControlMode::PercentOutput, 0); 
}
