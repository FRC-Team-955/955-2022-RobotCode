#include "hopper.h"

void Hopper::RunHopperMotor(int hopper_motor_percent_top,
                            int hopper_motor_percent_bottom) {
  talon_hopper_top.Set(ControlMode::PercentOutput,
                       std::min(hopper_motor_percent_top, max));
  talon_hopper_bottom.Set(ControlMode::PercentOutput,
                          std::min(hopper_motor_percent_bottom, max));
}