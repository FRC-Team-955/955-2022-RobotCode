#include "elevator.h"
//add soft limit
//add brake function
using namespace frc;
void Elevator::ElevatorMove(int joystick_position)
{
if(solenoid0.Get() == 1)
{
    elevator_motor.SetNeutralMode(NeutralMode::Brake);
    elevator_motor.Set(ControlMode::PercentOutput, 0);
}
if(limit_switch_top.Get() == 1 && joystick_position > 0)
    {
    elevator_motor.SetNeutralMode(NeutralMode::Brake);
    elevator_motor.Set(ControlMode::PercentOutput, 0);
    }
else if(limit_switch_top.Get() == 1 && joystick_position < 0)
    {
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position);
    }
if(limit_switch_bottom.Get() == 1 && joystick_position < 0)
    {
    elevator_motor.SetNeutralMode(NeutralMode::Brake);
    elevator_motor.Set(ControlMode::PercentOutput, 0);
    }
else if(limit_switch_bottom.Get() == 1 && joystick_position > 0)
    {
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position);
    }
if(elevator_motor.GetSelectedSensorPosition() > 4000)
    {
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position * 0.5 );
    }
else if(elevator_motor.GetSelectedSensorPosition() < 1000)
    {
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position * 0.5 );
    }    
}

void Elevator::LockElevator()
{
    solenoid0.Set(1);
    elevator_motor.SetNeutralMode(NeutralMode::Brake);
    elevator_motor.Set(ControlMode::PercentOutput, 0);
}

void Elevator::UnlockElevator()
{
    solenoid0.Set(0);
}

