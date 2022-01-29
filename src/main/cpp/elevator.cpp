#include "elevator.h"
using namespace rev;
using namespace frc;
void Elevator::ElevatorMove(int joystick_position)
{
if(bot_switch == 0 && joystick_position < 0)
{
    elevator_motor.Set(ControlMode::PercentOutput, 0);
}

if(solenoid0.Get() == 1)
{
    elevator_motor.Set(ControlMode::PercentOutput, 0);
}
else if(limit_switch_top.Get() == 1 && joystick_position > 0)
{
    elevator_motor.Set(ControlMode::PercentOutput, 0);
}
else if(limit_switch_top.Get() == 1 && joystick_position < 0)
{
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position);
}
else if(limit_switch_bottom.Get() == 1 && joystick_position < 0)
{
    elevator_motor.Set(ControlMode::PercentOutput, 0);
}
else if(limit_switch_bottom.Get() == 1 && joystick_position > 0)
{
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position);
}
else if(elevator_motor.GetSelectedSensorPosition() > 4000)
{
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position * 0.5 );
}
else if(elevator_motor.GetSelectedSensorPosition() < 1000)
{
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position * 0.5 );
}
else if(elevator_motor.GetSelectedSensorPosition() < 4000 && elevator_motor.GetSelectedSensorPosition() > 1000 )    
{
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position);
}
}

void Elevator::LockElevator()
{
    solenoid0.Set(1);
    elevator_motor.Set(ControlMode::PercentOutput, 0);
}

void Elevator::UnlockElevator()
{
    solenoid0.Set(0);
}


