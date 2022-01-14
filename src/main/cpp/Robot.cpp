// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
//test2
#include "Robot.h"
#include "ctre/Phoenix.h"
#include <frc/Joystick.h>
<<<<<<< Updated upstream
//test
=======
#include "drivebase.h"
//#include "frc/CameraServer.h" //Untested Cam Code
//
using namespace frc;

DriveBase *drivebase;
//CameraServer *cam; //Untested Cam Code

>>>>>>> Stashed changes
void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {

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
