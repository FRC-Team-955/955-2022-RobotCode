
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
Intake intake;
BallManager ball_manager;
XYalign align;
Shooter shooter;
Hopper hopper;
Elevator elevator;

ButtonToggle elevator_lock;
ButtonToggle intake_deploy;

frc::Timer * m_timer_intake;

bool inital_run = false;

void Robot::RobotInit() {
  frc::CameraServer::GetInstance()->StartAutomaticCapture();

  m_timer_intake = new frc::Timer();
}
void Robot::RobotPeriodic() {}
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {
}
void Robot::TeleopPeriodic() {

  if(joystick_0.GetRawAxis(Joy0Const::kshoot_trigger)&& align.hasTargetLimeLight())
  {
    //runs align if the trigger is pressed and there is a target
    align.test();
  }
  else
  {
    //runs drivebase
    drivebase.Drive();
    ball_manager.CheckHopperState();

    //toggle intake
    if(intake_deploy.GetToggle(joystick_1.GetRawButton(Joy1Const::kintake_deploy_button))){
      intake.PistonUp();
    }else{
      intake.PistonDown();
    }

    //Ball manager
    if(joystick_1.GetRawButtonPressed(Joy1Const::kintake_run_button)){
      intake.RunIntake(TelopConst::kintake_speed);

      //resets the intake timer to 0
      m_timer_intake->Start();
      m_timer_intake->Reset();

      inital_run=true;
    }else{
      intake.StopIntake();
    }
    
    //timer is reset when the intake is run and then it runs for 5s
    if(m_timer_intake->Get()<5_s && inital_run){
      ball_manager.LoadHopper();
    }

    //elevator
    //unlocks and locks
    if(elevator_lock.GetToggleNoDebounce(joystick_1.GetRawButton(Joy1Const::kelevator_lock_button))){
      elevator.LockElevator();
    }else{
      elevator.UnlockElevator();
    }
    //elevator only runs if is unlocked
    elevator.ElevatorMove(joystick_1.GetRawAxis(Joy1Const::kelevator_axis));
  }
}
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}
void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
