#include "drivebase.h"

void DriveBase::Drive(){
    bool isQuickTurn = joystick.GetRawButton(Joy0Const::kquick_turn_button);
    m_robotDrive.CurvatureDrive(joystick.GetRawAxis(Joy0Const::kdrive_speed_axis), joystick.GetRawAxis(Joy0Const::kquick_turn_button), isQuickTurn);
    //m_pidController.SetReference(rotations, rev::ControlType::kPosition);
}
