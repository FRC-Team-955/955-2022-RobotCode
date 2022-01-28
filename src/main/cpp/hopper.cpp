#include "hopper.h"

void Hopper::Run_Hopper_Motor(int hopper_motor_percent_top, int hopper_motor_percent_bottom){
    talon_hopper_top.Set(ControlMode::PercentOutput, hopper_motor_percent_top * max);
    talon_hopper_bottom.Set(ControlMode::PercentOutput, hopper_motor_percent_bottom * max);
}