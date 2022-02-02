#include "hopper.h"

void Hopper::RunHopperMotor(int hopper_motor_top_percent, int hopper_motor_bottom_percent) {
  talon_hopper_top.Set(ControlMode::PercentOutput, hopper_motor_top_percent * max_percent);
  talon_hopper_bottom.Set(ControlMode::PercentOutput, hopper_motor_bottom_percent * max_percent);
}


void Hopper::DiplayHopperInfo(){
  frc::Shuffleboard::GetTab("Telop").Add("Hopper Bottom Amp",talon_hopper_bottom.GetOutputCurrent());
  frc::Shuffleboard::GetTab("Telop").Add("Hopper Top Amp",talon_hopper_top.GetOutputCurrent());
}

