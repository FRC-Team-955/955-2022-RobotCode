#include "shooter.h"
using namespace frc;

float Shooter::ShootAtVelocity(int velocity) {
  shooter_talon.Set(ControlMode::Velocity, velocity);
  return shooter_talon.GetSelectedSensorVelocity(0);
}

void Shooter::ShootPercentOutput(int percent) {
  shooter_talon.Set(ControlMode::PercentOutput, percent);
}

void Shooter::ShooterAmp(int amp) {
  amp = shooter_talon.GetOutputCurrent();
}

void Shooter::ShooterVelocity(int velocity) {
  velocity = shooter_talon.GetSelectedSensorVelocity(0);
}