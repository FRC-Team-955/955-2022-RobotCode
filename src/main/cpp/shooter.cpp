#include "shooter.h"
using namespace frc;
using namespace rev;

void Shooter::ShootPercentOutput(int percent){
    shooterneo_lead.Set(percent);
}

void IndependentControl(int leadvelocity, int followvelocity){
    double SetPoint = 0.0;
    m_pidController.SetReference(SetPoint, rev::ControlType::kVelocity);
    m_pidController2.SetReference(SetPoint, rev::ControlType::kVelocity);

    return shooterneo_lead.GetEncoder().GetVelocity();

}
