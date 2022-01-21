#include "shooter.h"
using namespace std; 
using namespace frc; 

float Shooter::ShootAtVelocity(int velocity) {
    shootertalon_lead.Set(ControlMode::Velocity, velocity);
    shootertalon_follow.Set(ControlMode::Follower, 1);

    return shootertalon_lead.GetSelectedSensorVelocity(0);
}

void Shooter::ShootPercentOutput(int percent){
    shootertalon_lead.Set(ControlMode::PercentOutput, percent);
    shootertalon_follow.Set(ControlMode::PercentOutput, percent);
}

float Shooter::IndependentControl(int velocity_lead, int velocity_follow) {
    shootertalon_lead.Set(ControlMode::Velocity, velocity_lead);
    shootertalon_follow.Set(ControlMode::Velocity, velocity_follow);

    

    return shootertalon_lead.GetSelectedSensorVelocity(0);
}