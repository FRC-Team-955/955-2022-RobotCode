#include "elevator.h"
using namespace frc;
void Elevator::ElevatorMove(int joystick_position)
{
if(bot_switch == 0 && joystick_position < 0)
{
    elevator_motor.Set(ControlMode::PercentOutput, 0);
}
else if(limit_switch_bottom.Get() == 1 && bot_switch == 0) 
{
    bot_switch == 1;
    elevator_motor.SetSelectedSensorPosition(0);
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
    if(joystick_position > 0)
    {
        elevator_motor.Set(ControlMode::PercentOutput, joystick_position * Joy1Const::elevator_slow_multiplier );
    }
    else
    {
       elevator_motor.Set(ControlMode::PercentOutput, joystick_position); 
    }
}
else if(elevator_motor.GetSelectedSensorPosition() < 1000 && joystick_position < 0)
{
     if(joystick_position < 0)
    {
        elevator_motor.Set(ControlMode::PercentOutput, joystick_position * Joy1Const::elevator_slow_multiplier );
    }
    else
    {
       elevator_motor.Set(ControlMode::PercentOutput, joystick_position); 
    }
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

void Elevator::LockElevator() {
  solenoid0.Set(1);
  elevator_motor.SetNeutralMode(NeutralMode::Brake);
  elevator_motor.Set(ControlMode::PercentOutput, 0);
}

bool Elevator::OffGround()
{
    if(elevator_motor.GetOutputCurrent() >= MechanismConst::climb_amperage)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


