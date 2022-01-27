
// Copyright (c) FIRT and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "ctre/Phoenix.h"
#include <cstdlib>
#include <cameraserver/CameraServer.h>

#include "settings.h"
#include "button_toggle.h"

#include "drivebase.h"
#include "shooter.h"
#include "hopper.h"
#include "elevator.h"

using namespace frc;

Joystick joystick_0{0};
Joystick joystick_1{1};

DriveBase drivebase;
Shooter shooter;
Hopper hopper;
Elevator elevator;

ButtonToggle elevator_lock;

void Robot::RobotInit() {
  frc::CameraServer::GetInstance()->StartAutomaticCapture();
}
void Robot::RobotPeriodic() {}
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() { 
  drivebase.Drive();
  shooter.ShootPercentOutput(std::abs(joystick_1.GetRawAxis(Joy1Const::kshooter_axis)));
  hopper.RunHopperMotor(joystick_1.GetRawAxis(Joy1Const::khopper_top_axis), joystick_1.GetRawAxis(Joy1Const::khopper_bottom_axis));
  elevator.ElevatorMove(joystick_1.GetRawAxis(Joy1Const::kelevator_axis));
  if(elevator_lock.GetToggleNoDebounce(joystick_1.GetRawButton(Joy1Const::kelevator_lock_button))){
    elevator.LockElevator();
  }else{
    elevator.UnlockElevator();
  }
}
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}
void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
