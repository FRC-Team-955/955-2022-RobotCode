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

#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/fs.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "auto.h"

#include "drivebase.h"

using namespace frc;

DriveBase *drivebase;

Auto * bryanauto;



frc::Trajectory set_trajectory;

// std::string color[2] = { "Blue", "Red"};

// //the position you are at, at the start of the game
// std::string position =0;
int state = 0;
// std::string test = "okay";

frc::SendableChooser<std::string> m_position_Chooser;
frc::SendableChooser<std::string> m_team_color_Chooser;

void Robot::RobotInit() {
  std::cout<<"robotinti"<<std::endl;
  
  fs::path deployDirectory = frc::filesystem::GetDeployDirectory();
  deployDirectory = deployDirectory / "paths" / "Unnamed.wpilib.json";
  std::cout<<deployDirectory.string()<<std::endl;

  set_trajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory.string());
  std::cout<<"trajc set in init"<<std::endl;


  //Add the options to the Choosers
  m_position_Chooser.AddOption("Left","Left");
  m_position_Chooser.AddOption("Right","Right");
  m_position_Chooser.AddOption("Middle","Middle");
  Shuffleboard::GetTab("Pre").Add("Robot Position", m_position_Chooser).WithWidget(frc::BuiltInWidgets::kComboBoxChooser);
  m_team_color_Chooser.AddOption("Blue", "Blue");
  m_team_color_Chooser.AddOption("Red", "Red");
  Shuffleboard::GetTab("Pre").Add("Team Color", m_team_color_Chooser).WithWidget(frc::BuiltInWidgets::kComboBoxChooser);

  Shuffleboard::SelectTab("Pre");
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  state = 0;

  //Gets the values from the Shuffleboard
  std::string auto_selection = Shuffleboard::GetTab("Pre").Add("Robot Position", "NA").GetEntry().GetString("NA");
  //The team color it defaults to Red jic you forget to set color (aka hope to win 50-50)
  // ball_manager.team_color = Shuffleboard::GetTab("Pre").Add("Robot Position", "NA").GetEntry().GetString("Red");
  
  std::cout<<"autoinit1"<<std::endl;

}

void Robot::AutonomousPeriodic() {
    std::cout<<"auto periodic"<<std::endl;
    bryanauto->GenerateTrajectory();

  if(state == 0){
    std::cout<<"state =0"<<std::endl;

    //bryanauto->SetTrajectory(set_trajectory);
    std::cout<<"settraj"<<std::endl;

    bryanauto-> Start();
    std::cout<<"start"<<std::endl;
    state = 1;
  }else if(state == 1){
    if(bryanauto -> RunRamsete()){
      
      state = 2;
      std::cout<<"it run"<<std::endl;
    }

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
}

void Robot::TeleopInit() {
  // drivebase = new DriveBase();
  // frc::CameraServer::GetInstance()->StartAutomaticCapture();
}
void Robot::TeleopPeriodic() { 
  // drivebase->Drive();
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
