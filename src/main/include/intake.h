#ifndef INTAKE
#define INTAKE
#include <iostream> 
#include "frc/Joystick.h"
#include "frc/Solenoid.h"
#include <ctre/Phoenix.h>
using namespace std;
using namespace frc; 

class Intake
{
public: 
void in();

private:
Joystick joystick {0}; 
TalonSRX motor {1}; 
Solenoid up {PneumaticsModuleType::CTREPCM, 0};
Solenoid down {PneumaticsModuleType::CTREPCM, 1};

};
#endif