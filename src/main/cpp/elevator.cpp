#include "elevator.h"
using namespace frc;
int Elevator::ElevatorMove(int joystick_position)
{
if(solenoid0.Get() == 1)
{
    return 1;
}
if(limit_switch_top.Get() == 1 && joystick_position > 0)
    {
    hopper_motor.Set(ControlMode::PercentOutput, 0);
    }
else if(limit_switch_bottom.Get() == 1 && joystick_position < 0)
    {
    hopper_motor.Set(ControlMode::PercentOutput, 0);
    }
else
    {
    hopper_motor.Set(ControlMode::PercentOutput, joystick_position);
    }
return 0;
}

void Elevator::LockElevator()
{
    solenoid0.Set(1);
}

void Elevator::UnlockElevator()
{
    solenoid0.Set(0);
}

