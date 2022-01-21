#include "shooter.h"
using namespace frc; 

float Shooter::ShootAtVelocity(int velocity) {
    shootertalon_lead.Set(ControlMode::Velocity, velocity);

    return shootertalon_lead.GetSelectedSensorVelocity(0);
}

void Shooter::ShootPercentOutput(int percent){
    shootertalon_lead.Set(ControlMode::PercentOutput, percent);
}


