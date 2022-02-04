#include "shooter.h"
using namespace frc;
using namespace rev;

float Shooter::ShootAtVelocity(int velocity) {
  shooter_talon.Set(ControlMode::Velocity, velocity);
  return shooter_talon.GetSelectedSensorVelocity(0);
void Shooter::ShootPercentOutput(int percent){
    shooterneo_lead.Set(percent);
}

void Shooter::ShootPercentOutput(int percent) {
  shooter_talon.Set(ControlMode::PercentOutput, percent);
} 
float IndependentControl(int leadvelocity, int followvelocity){
    double SetPoint = 0.0;
    m_pidController.SetReference(SetPoint, rev::ControlType::kVelocity);
    m_pidController2.SetReference(SetPoint, rev::ControlType::kVelocity);

    return shooterneo_lead.GetEncoder().GetVelocity();
    return shooterneo_follow.GetEncoder().GetVelocity();

}