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

void DriveBase::DriveBaseAmp(int amp1, int amp2, int amp3, int amp4) {
  amp1 = m_leftLeadMotor.GetOutputCurrent(); 
  amp2 = m_leftFollowMotor.GetOutputCurrent();
  amp3 = m_rightLeadMotor.GetOutputCurrent();
  amp4 = m_rightFollowMotor.GetOutputCurrent(); 
}

void DriveBase::DriveBaseSpeed(int speed, double number) {
  number = 2*3.14159*0.1016/609; 
  SetVelocityConversionFactor(number);
  GetVelocityConversionFactor();
  speed = GetVelocity();

}