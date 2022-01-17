#include "elevator.h"
using namespace frc;
using namespace std;
int Elevator::ElevatorMove()
{
if(solenoid0.Get() == 1)
{
    return 1;
}
if(limit_switch_top.Get() == 1 && joy0.GetRawAxis(0) > 0)
    {
    hopper_motor.Set(ControlMode::PercentOutput, 0);
    }
else if(limit_switch_bottom.Get() == 1 && joy0.GetRawAxis(0) < 0)
    {
    hopper_motor.Set(ControlMode::PercentOutput, 0);
    }
else
    {
    hopper_motor.Set(ControlMode::PercentOutput, joy0.GetRawAxis(0));
    }
return 0;
}

void Elevator::LockElevator()
{
if(joy0.GetRawButton(1) == true && joy0.GetRawButton(2) == false)
    {
    solenoid0.Set(1);
    }
}

void Elevator::UnlockElevator()
{
if(joy0.GetRawButton(2) == true && joy0.GetRawButton(1) == false)
    {
    solenoid0.Set(0);
    }
}

