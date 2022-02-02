#include "shooter.h"
using namespace rev;

float Shooter::ShootAtVelocity(int velocity) {
    double SetPoint = 0.0;
    m_pidController.SetReference(SetPoint, rev::ControlType::kVelocity);
    shooterneo_follow.Follow(shooterneo_lead);

    return shooterneo_lead.GetVelocity();

}

void Shooter::ShootPercentOutput(int percent){
    shooterneo_lead.Set(percent);
}

void IndependentControl(int leadvelocity, int followvelocity){
    double SetPoint = 0.0;
    CANSparkMax::kFollowerDisabled;
    m_pidController.SetReference(SetPoint, rev::ControlType::kVelocity);
    m_pidController2.SetReference(SetPoint, rev::ControlType::kVelocity);

}





