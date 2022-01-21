#include "shooter.h"
using namespace std; 
using namespace frc; 

void Shooter::ShootAtVelocity(int V)
{
shootertalon_lead.Set(ControlMode::Velocity, V);
shootertalon_follow.Follow(shootertalon_lead);

}