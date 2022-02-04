#include "shooter.h"
using namespace frc;
using namespace rev;

void Shooter::ShootPercentOutput(int percent1, int percent2){
    shooterneo_lead.Set(percent1);
    shooterneo_follow.Set(percent2);
}

float Shooter::IndependentControl(int lead_velocity, int follow_velocity, bool return_value=false){
    m_pidController.SetReference(lead_velocity, rev::ControlType::kVelocity);
    m_pidController2.SetReference(follow_velocity, rev::ControlType::kVelocity);

    if(return_value) return shooterneo_lead.GetEncoder().GetVelocity();
    return shooterneo_follow.GetEncoder().GetVelocity();

}
