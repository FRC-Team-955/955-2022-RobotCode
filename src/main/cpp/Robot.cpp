// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
// test2
#include "Robot.h"
#include "ctre/Phoenix.h"
#include "drivebase.h"
#include <cameraserver/CameraServer.h>
#include <frc/Joystick.h>
#include "intake.h"
#include "hopper.h"

using namespace frc;

DriveBase *drivebase;
Intake *i1;
Hopper *h1;

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  drivebase = new DriveBase();
  i1 = new Intake();
  h1 = new Hopper();
  frc::CameraServer::GetInstance()->StartAutomaticCapture();
}
void Robot::TeleopPeriodic() { 
  drivebase->Drive(); 
  i1 -> intake_run();
  h1 -> Run_Hopper_Motor();
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
