// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
// test2
#include "Robot.h"
#include <iostream>

#include "string"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <cameraserver/CameraServer.h>
#include "ctre/Phoenix.h"
#include <frc/Joystick.h>

#include "drivebase.h"
#include "auto.h"

using namespace frc;

DriveBase *drivebase;

Auto * bryanauto;

std::string color[2] = { "Blue", "Red"};

//the position you are at, at the start of the game
std::string position =0;
int state = 0;
std::string test = "okay";

void Robot::RobotInit() {
  frc::Shuffleboard::GetTab("Auto");
  frc::Shuffleboard::GetTab("Telop");
  frc::Shuffleboard::GetTab("End Game");

  frc::Shuffleboard::SelectTab(0);
  frc::SmartDashboard::SetDefaultStringArray("Team Color",color);
  

}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  state = 0;


}
void Robot::AutonomousPeriodic() {
  // if(state == 0){
  //   bryanauto->SetTrajectory(trajectory_toshoot);
  //   bryanauto-> Start();
  //   state == 1
  // }else if(state == 1){
  //   if(bryanauto -> RunRamsete()){
  //     state = 2;
  //   }
  // }else if(state == 2){
  //   bryanauto->SetTrajectory(trajectory_pickupballs);
  //   bryanauto-> Start();
  //   state = 3;
  // }else if(state ==3){
  //   if(bryanauto->RunRamsete()){
  //     state=4;
  //   }
  // }
}

void Robot::TeleopInit() {
  drivebase = new DriveBase();
  frc::CameraServer::GetInstance()->StartAutomaticCapture();
}
void Robot::TeleopPeriodic() { drivebase->Drive(); }

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
