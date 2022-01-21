#include "shooter.h"
using namespace std; 
using namespace frc; 

float Shooter::ShootAtVelocity(int Velocity) {
    shootertalon_lead.Set(ControlMode::Velocity, Velocity);
    shootertalon_follow.Set(ControlMode::Follower, 1);

    return shootertalon_lead.GetSelectedSensorVelocity(0);
}

void Shooter::ShootPercentOutput(int Percent){
    shootertalon_lead.Set(ControlMode::PercentOutput, Percent);
}

float Shooter::IndependentControl(int VelocityLead, int VelocityFollow) {
    shootertalon_lead.Set(ControlMode::Velocity, VelocityLead);
    shootertalon_follow.Set(ControlMode::Velocity, VelocityFollow);

    

    return shootertalon_lead.GetSelectedSensorVelocity(0);
}