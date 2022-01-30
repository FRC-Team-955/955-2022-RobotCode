
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "ctre/Phoenix.h"
#include <cameraserver/CameraServer.h>

#include <frc/smartdashboard/SendableChooser.h>

#include "colorsensor.h"
#include "drivebase.h"
// #include "feedbacksystem.h"

using namespace frc;

Joystick *joystick;

DriveBase *drivebase;
ColorSensor *color_sensor;
frc::SendableChooser<std::string> m_positionChooser;

void Robot::RobotInit() {
  drivebase = new DriveBase();
  color_sensor = new ColorSensor();
  frc::CameraServer::GetInstance()->StartAutomaticCapture();

  frc::ShuffleboardTab& tabpre = Shuffleboard::GetTab("Pre");
  frc::ShuffleboardTab& tabauto = Shuffleboard::GetTab("Auto");
  frc::ShuffleboardTab& tabtelop = Shuffleboard::GetTab("Telop");
  frc::ShuffleboardTab& tableend = Shuffleboard::GetTab("End Game");

  m_positionChooser.AddOption("Left","Left");
  m_positionChooser.AddOption("Right","Right");
  m_positionChooser.AddOption("Middle","Middle");

  tabpre.Add("Robot Position", m_positionChooser).WithWidget(frc::BuiltInWidgets::kComboBoxChooser);

  
}
void Robot::RobotPeriodic() {}
void Robot::AutonomousInit() {
  Shuffleboard::SelectTab("Auto");
  // m_autoposition  = Shuffleboard::GetTab("Pre").Add
}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {
  Shuffleboard::SelectTab("Telop");

}
void Robot::TeleopPeriodic() { 
  drivebase->Drive();
  drivebase->DisplayDriveInfo();

 }
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}
void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
