#include "shooter.h"
using namespace rev;

float Shooter::ShootAtVelocity(int velocity) {
    //shooterneo_lead.Set()
    CANSparkMax::Follow(const shooterneo_lead);

    return shootertalon_lead.GetSelectedSensorVelocity(0);
}

void Shooter::ShootPercentOutput(int percent){
    //shootertalon_lead.Set(percent);
}

void IndependentControl(int leadvelocity, int followvelocity){
    CANSparkMax::kFollowerDisabled
    shooterneo_lead.Set
    shooterneo.follow.Set
}
