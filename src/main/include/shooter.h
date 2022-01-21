#ifndef SHOOTER
#define SHOOTER
#include <iostream> 
#include "frc/Joystick.h"
#include <ctre/Phoenix.h>
using namespace std;
using namespace frc; 

class Shooter
{

public: 
Shooter(){shootertalon_follow.SetInverted(1);}
void ShootAtVelocity(int V);


private: 
TalonSRX shootertalon_lead {1}; 
TalonSRX shootertalon_follow {2}; 
};
#endif
