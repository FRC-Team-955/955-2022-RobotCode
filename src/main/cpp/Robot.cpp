// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "xy_align.h"
#include "balldetect.h"



XYalign *xy_align;
BallDetect *balldetect;

photonlib::PhotonCamera camera{"ball"};


void Robot::RobotInit() {
  //xy_align = new XYalign();  

}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {

}
void Robot::TeleopPeriodic() {
  photonlib::PhotonPipelineResult result = camera.GetLatestResult();
  std::cout<<balldetect -> BallDetectorX(result)<<std::endl;
 

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
