#include "drivebase.h"

void DriveBase::Drive(photonlib::PhotonPipelineResult result) {

  BallAimbot = joystick.GetRawButton(Joy0Const::kball_aimbot_button);
  isQuickTurn = joystick.GetRawButton(Joy0Const::kquick_turn_button);

  if (buttontoggle.GetToggle(
          joystick.GetRawButton(Joy0Const::kreverse_drive))) {
    m_robotDrive.CurvatureDrive(
        -joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        -joystick.GetRawAxis(Joy0Const::kdrive_curvature_axis), isQuickTurn);

  } else {
    if (BallAimbot == true && ball_detector.BallDetectorX(result) < 10000) {
      m_robotDrive.CurvatureDrive(
        joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        (joystick.GetRawAxis(Joy0Const::kdrive_curvature_axis) + (ball_detector.BallDetectorX(result)/DriveConst::kturn_div)), isQuickTurn);
    } else {
      m_robotDrive.CurvatureDrive(
          joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
          joystick.GetRawAxis(Joy0Const::kdrive_curvature_axis), isQuickTurn);
    }
  }
}