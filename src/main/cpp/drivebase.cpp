#include "drivebase.h"
#include <frc/smartdashboard/SmartDashboard.h>

void DriveBase::Drive() {

  if (joystick.GetRawButtonPressed(Joy0Const::kquick_turn_button)) {
    isQuickTurn = !isQuickTurn;
  }
  if (joystick.GetRawButtonPressed(Joy0Const::kreverse_drive)) {
    ReverseDrive = !ReverseDrive;
  }
  if (ReverseDrive == false) {
    m_robotDrive.CurvatureDrive(
        joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        joystick.GetRawAxis(Joy0Const::kdrive_curvature_axis), isQuickTurn);
    frc::SmartDashboard::PutBoolean("isQuickTurn", isQuickTurn);
    frc::SmartDashboard::PutBoolean("Reverse Drive", ReverseDrive);

  } else {
    m_robotDrive.CurvatureDrive(
        -joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        joystick.GetRawAxis(Joy0Const::kdrive_curvature_axis), isQuickTurn);
    frc::SmartDashboard::PutBoolean("isQuickTurn", isQuickTurn);

    frc::SmartDashboard::PutBoolean("Reverse Drive", ReverseDrive);
  }
   

  // m_pidController.SetReference(rotations, rev::ControlType::kPosition);
}
