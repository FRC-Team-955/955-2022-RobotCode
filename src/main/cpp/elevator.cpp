#include "elevator.h"
using namespace rev;
using namespace frc;
void Elevator::ElevatorMove(int joystick_position)
{
if(solenoid0.Get() == 1)
{
    elevator_motor.SetIdleMode(CANSparkMax::IdleMode::kBrake);
    elevator_motor.Set(0);
}
if(limit_switch_top.Get() == 1 && joystick_position > 0)
{
    elevator_motor.SetIdleMode(CANSparkMax::IdleMode::kBrake);
    elevator_motor.Set(0);
}
else if(limit_switch_top.Get() == 1 && joystick_position < 0)
{
    elevator_motor.Set(joystick_position);
}
if(limit_switch_bottom.Get() == 1 && joystick_position < 0)
{
    elevator_motor.SetIdleMode(CANSparkMax::IdleMode::kBrake);
    elevator_motor.Set(0);
}
else if(limit_switch_bottom.Get() == 1 && joystick_position > 0)
{
    elevator_motor.Set(joystick_position);
}
if(elevator_motor.GetEncoder().GetPosition() > 4000)
{
    elevator_motor.Set(joystick_position * 0.5 );
}
else if(elevator_motor.GetEncoder().GetPosition() < 1000)
{
    elevator_motor.Set(joystick_position * 0.5 );
}    
}

void Elevator::LockElevator()
{
    solenoid0.Set(1);
    elevator_motor.SetIdleMode(CANSparkMax::IdleMode::kBrake);
    elevator_motor.Set(0);
}

void Elevator::UnlockElevator()
{
    solenoid0.Set(0);
}

