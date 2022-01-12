#include "drivebase.h"

void DriveBase::Drive(){
	
    bool isQuickTurn = false;
	m_rightFollowMotor.Follow(m_rightLeadMotor);
    m_robotDrive.CurvatureDrive(joystick.GetRawAxis(1), joystick.GetRawAxis(4), isQuickTurn);
    //m_pidController.SetReference(rotations, rev::ControlType::kPosition);
}
