#include "drivebase.h"

void DriveBase::Drive() {

  isQuickTurn = joystick.GetRawButton(Joy0Const::kquick_turn_button);

  if (buttontoggle.GetToggle(joystick.GetRawButton(Joy0Const::kreverse_drive))) {
    m_robotDrive.CurvatureDrive(
        -joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        -joystick.GetRawAxis(Joy0Const::kdrive_curvature_axis), isQuickTurn);

  } else {
    m_robotDrive.CurvatureDrive(
        joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        joystick.GetRawAxis(Joy0Const::kdrive_curvature_axis), isQuickTurn);
  }
}