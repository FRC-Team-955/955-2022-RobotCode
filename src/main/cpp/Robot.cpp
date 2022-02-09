// Copyright (c) FIRT and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "ctre/Phoenix.h"
#include <cameraserver/CameraServer.h>
#include "colorsensor.h"
#include "drivebase.h"

using namespace frc;

Joystick *joystick;

DriveBase *drivebase;
ColorSensor *color_sensor;
photonlib::PhotonCamera camera{"BallDetect"};

void Robot::RobotInit() {
  frc::CameraServer::StartAutomaticCapture();
  cs::CvSink cvSink = frc::CameraServer::GetVideo();
  cs::CvSource outputStream = frc::CameraServer::PutVideo("Blur", 640, 480);
  
  // frc::CameraServer::GetInstance()->StartAutomaticCapture();
}
void Robot::RobotPeriodic() {}
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {
  drivebase = new DriveBase();
  color_sensor = new ColorSensor();
}
void Robot::TeleopPeriodic() { 
  photonlib::PhotonPipelineResult result = camera.GetLatestResult();
  drivebase->Drive(result);
}
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}
void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
