#include "shooter.h"
using namespace std; 
using namespace frc; 

void Shooter::ShootAtVelocity(int V)
{
Motor.Set(ControlMode::Velocity, V);
}