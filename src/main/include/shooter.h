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
void ShootAtVelocity(int V);


private: 
TalonSRX Motor {1}; 
};
#endif
