#include "hopper.h"

void Hopper::Run_Hopper_Motor(int percent){
    talon_hopper.Set(ControlMode::PercentOutput, percent);
}