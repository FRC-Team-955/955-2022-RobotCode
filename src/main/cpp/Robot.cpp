#include "Robot.h"
#include "ctre/Phoenix.h"
#include <cameraserver/CameraServer.h>
#include <frc/smartdashboard/smartdashboard.h>

#include "drivebase.h"
#include "colorsensor.h"

using namespace frc;

Joystick *joystick;

DriveBase *drivebase;
ColorSensor *color_sensor;

void Robot::RobotInit() {
  frc::CameraServer::GetInstance()->StartAutomaticCapture();
}
void Robot::RobotPeriodic() {}
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}
void Robot::TeleopInit() {
  joystick = new Joystick(0);

  drivebase = new DriveBase();
  color_sensor = new ColorSensor();
}
void Robot::TeleopPeriodic(){
  drivebase->Drive();
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
