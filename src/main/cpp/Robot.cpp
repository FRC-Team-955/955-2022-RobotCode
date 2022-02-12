// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "auto.h"

#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/fs.h>

frc::Trajectory set_trajectory;

Auto * bryanauto;


int state = 0;

void Robot::RobotInit() {
  std::cout<<"robotinti"<<std::endl;
  
  fs::path deployDirectory = frc::filesystem::GetDeployDirectory();

  deployDirectory = deployDirectory / "paths" / "Unnamed.wpilib.json";
  std::cout<<"bruh" << deployDirectory.string()<<std::endl;

  set_trajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory.string());
  std::cout<<"trajc set in init"<<std::endl;

}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {
  if(state == 0){
    std::cout<<"state =0"<<std::endl;

    // bryanauto->SetTrajectory(set_trajectory);
    std::cout<<"settraj"<<std::endl;

    bryanauto-> Start();
    std::cout<<"start"<<std::endl;
    state = 1;
  }else if(state == 1){
    if(bryanauto -> RunRamsete()){
      
      state = 2;
      std::cout<<"it run"<<std::endl;
    }
  }
}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
