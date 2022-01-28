#include "shooter.h"
using namespace rev;

float Shooter::ShootAtVelocity(int velocity) {
    shooterneo_lead.rev(ControlMode::Velocity, velocity);
    CANSparkMax::Follow(const shooterneo_lead);

    return shootertalon_lead.GetSelectedSensorVelocity(0);
}

void Shooter::ShootPercentOutput(int percent){
    shootertalon_lead.Set(percent);
}

void IndependentControl(int leadvelocity, int followvelocity){
    CANSparkMax::kFollowerDisabled;
    //shooterneo_lead.rev(ControlMode::Velocity, velocity)
    //shooterneo_follow.rev(ControlMode::Velocity, velocity)
}





