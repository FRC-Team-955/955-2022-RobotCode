
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "ctre/Phoenix.h"
#include <cameraserver/CameraServer.h>

#include <frc/smartdashboard/SendableChooser.h>

#include "colorsensor.h"
#include "drivebase.h"

#include <frc/Timer.h>
#include "feedbacksystem.h"

using namespace frc;

Joystick *joystick;

DriveBase *drivebase;
ColorSensor *color_sensor;
frc::Timer* m_timer;

frc::SendableChooser<std::string> m_positionChooser;

void Robot::RobotInit() {
  m_timer = new frc::Timer();
  drivebase = new DriveBase();
  color_sensor = new ColorSensor();
  frc::CameraServer::GetInstance()->StartAutomaticCapture();
  frc::ShuffleboardTab& tabpre = Shuffleboard::GetTab("Pre");
  frc::ShuffleboardTab& tableend = Shuffleboard::GetTab("End Game");
  frc::ShuffleboardTab& tabtelop = Shuffleboard::GetTab("Telop");
  frc::ShuffleboardTab& tabauto = Shuffleboard::GetTab("Auto");


  m_positionChooser.AddOption("Left","Left");
  m_positionChooser.AddOption("Right","Right");
  m_positionChooser.AddOption("Middle","Middle");

  tabpre.Add("Robot Position", m_positionChooser).WithWidget(frc::BuiltInWidgets::kComboBoxChooser);

  
}
void Robot::RobotPeriodic() {}
void Robot::AutonomousInit() {
  Shuffleboard::SelectTab("Auto");
}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {

  Shuffleboard::SelectTab("Telop");
  m_timer->Start();

}
void Robot::TeleopPeriodic() {

  drivebase->Drive();

  //Change to if (m_timer->GetMatchTime() > 10_s){ for the final version
  if (m_timer->Get() > 10_s){
    Shuffleboard::SelectTab("End Game");
  }

  // ShuffleBoard Stuff
  drivebase->DisplayDriveInfo();

 }
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}
void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
