#include "hopper.h"

void Hopper::Run_Hopper_Motor(int hopper_motor_percent1, int hopper_motor_percent2, int hopper_motor_percent3){
    talon_hopper1.Set(ControlMode::PercentOutput, hopper_motor_percent1);
    talon_hopper2.Set(ControlMode::PercentOutput, hopper_motor_percent2);
    talon_hopper3.Set(ControlMode::PercentOutput, hopper_motor_percent3);
}