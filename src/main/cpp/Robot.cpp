
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "ctre/Phoenix.h"
#include <cameraserver/CameraServer.h>
#include "rev/CANSparkMax.h"
// #include "drivebase.h"
// #include "colorsensor.h"
#include "settings.h"

using namespace rev;

// Joystick *joystick;

// DriveBase *drivebase;
// ColorSensor *color_sensor;

  CANSparkMax m_leftLeadMotor{5,
                              CANSparkMax::MotorType::kBrushless};
  // CANSparkMax m_rightLeadMotor{DriveConst::kright_lead_neo_number,
  //                              CANSparkMax::MotorType::kBrushless};
  // CANSparkMax m_leftFollowMotor{DriveConst::kleft_follow_neo_number,
  //                               CANSparkMax::MotorType::kBrushless};
  // CANSparkMax m_rightFollowMotor{DriveConst::kright_follow_neo_number,
  //                                CANSparkMax::MotorType::kBrushless};

void Robot::RobotInit() {
  // frc::CameraServer::GetInstance()->StartAutomaticCapture();
}
void Robot::RobotPeriodic() {}
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {
  // drivebase = new DriveBase();
  // color_sensor = new ColorSensor();
}
void Robot::TeleopPeriodic() { 
  // drivebase->Drive(); 
  m_leftLeadMotor.Set(.5);
  }
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}
void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
