// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "omnidrive.h"
#include "settings.h"
using namespace frc;
TalonSRX *rightLeadMotor, *leftLeadMotor, *rightFollowerMotor, *leftFollowerMotor;
Omnidrive *omnidrive;
Joystick *joy;


void Robot::RobotInit() {

}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  rightLeadMotor = new TalonSRX(DriveConst::kright_lead_port);
  leftLeadMotor = new TalonSRX(DriveConst::kleft_lead_port);
  rightFollowerMotor = new TalonSRX(DriveConst::kright_follower_port);
  leftFollowerMotor = new TalonSRX(DriveConst::kleft_follower_port);
  joy = new Joystick(0);
  omnidrive = new Omnidrive(joy, rightLeadMotor, leftLeadMotor, rightFollowerMotor, leftFollowerMotor);
  
}
void Robot::TeleopPeriodic() {
omnidrive->Drive();
// rightLeadMotor->Set(ControlMode::PercentOutput, 0.1);
// rightFollowerMotor->Set(ControlMode::PercentOutput, 0.1);
// leftFollowerMotor->Set(ControlMode::PercentOutput, -0.1);
// leftLeadMotor->Set(ControlMode::PercentOutput, -0.1);

}

void Robot::DisabledInit() {
  delete rightLeadMotor;
  delete leftLeadMotor;
  delete rightFollowerMotor;
  delete leftFollowerMotor;
}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
