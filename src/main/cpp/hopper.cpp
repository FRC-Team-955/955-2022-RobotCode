#include "hopper.h"

void Hopper::RunHopperMotor(int hopper_motor_top_percent, int hopper_motor_bottom_percent) {
  talon_hopper_top.Set(ControlMode::PercentOutput, hopper_motor_top_percent * max_percent);
  talon_hopper_bottom.Set(ControlMode::PercentOutput, hopper_motor_bottom_percent * max_percent);
}

void Hopper::HopperAmp(int amp1, int amp2) {
  amp1 = talon_hopper_bottom.GetOutputCurrent();
  amp2 = talon_hopper_top.GetOutputCurrent();
 
}

