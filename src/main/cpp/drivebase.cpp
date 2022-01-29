#include "drivebase.h"
#include <frc/smartdashboard/SmartDashboard.h>

void DriveBase::Drive() {
  bool isQuickTurn = joystick.GetRawButton(Joy0Const::kquick_turn_button);

  if (joystick.GetRawButtonPressed(Joy0Const::kreverse_drive)) {
    ReverseDrive = !ReverseDrive;
  }
  if (ReverseDrive == false) {
    m_robotDrive.CurvatureDrive(
        joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        joystick.GetRawAxis(Joy0Const::kquick_turn_button), isQuickTurn);
    frc::SmartDashboard::PutBoolean("Reverse Drive", ReverseDrive);

  } else {
    m_robotDrive.CurvatureDrive(
        -joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        -joystick.GetRawAxis(Joy0Const::kquick_turn_button), isQuickTurn);
    frc::SmartDashboard::PutBoolean("Reverse Drive", ReverseDrive);
  }

  // m_pidController.SetReference(rotations, rev::ControlType::kPosition);
}

std::array<double,4> DriveBase::DriveBaseAmp() {
  return {
  m_leftLeadMotor.GetOutputCurrent(),m_leftFollowMotor.GetOutputCurrent(),
  m_rightLeadMotor.GetOutputCurrent(),m_rightFollowMotor.GetOutputCurrent()} ; 
}

// void DriveBase::DriveBaseSpeed(int speedleft, int speedright, double number) {
//   number = 2*3.14159*0.1016/609; 
//   m_leftLeadMotor.SetVelocityConversionFactor(number);
//   GetVelocityConversionFactor();
//   speedleft= GetVelocity();
//   m_rightLeadMotor.SetVelocityConversionFactor(number)
//   GetVelocityConversionFactor();
//   speedright = GetVelocity(); 

// }