// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
//test2
#include "Robot.h"
#include "ctre/Phoenix.h"
<<<<<<< Updated upstream
#include <frc/Joystick.h>
//test
void Robot::RobotInit() {}
=======
#include <cameraserver/CameraServer.h>
#include "elevator.h"
#include "colorsensor.h"
#include "drivebase.h"
#include <frc/Timer.h> 

using namespace std; 
using namespace frc;

Joystick *joystick;

DriveBase *drivebase;
ColorSensor *color_sensor;

void Robot::RobotInit() {
  frc::CameraServer::GetInstance()->StartAutomaticCapture();
}
>>>>>>> Stashed changes
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}
<<<<<<< Updated upstream

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {

=======
void Robot::TeleopInit() {
  drivebase = new DriveBase();
  color_sensor = new ColorSensor();
}
void Robot::TeleopPeriodic() { 
  drivebase->Drive(); 
 
>>>>>>> Stashed changes
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
