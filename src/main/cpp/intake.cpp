#include "intake.h"
using namespace std;
using namespace frc; 

void Intake::in()
{
cout << joystick.GetRawButton(0) << endl; 
cout << joystick.GetRawButton(1) << endl; 
cout << motor.GetOutputCurrent() << endl; 

if (joystick.GetRawButton(0) == 1)
{
motor.Set(ControlMode::PercentOutput, .3);
up.Set(1);
}

if (motor.GetOutputCurrent() >= 10)
{
motor.Set(ControlMode::PercentOutput, -.3);
down.Set(1); 
} 

else 
{
motor.Set(ControlMode::PercentOutput, 0);
up.Set(0);
down.Set(0);
}

}


