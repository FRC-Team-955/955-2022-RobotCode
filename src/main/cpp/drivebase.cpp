#include "drivebase.h"

void DriveBase::Drive(){
	
    bool isQuickTurn = joystick.GetRawButton(0);
	m_rightFollowMotor.Follow(m_rightLeadMotor);
    m_leftFollowMotor.Follow(m_leftLeadMotor);
    m_robotDrive.CurvatureDrive(joystick.GetRawAxis(1), joystick.GetRawAxis(4), isQuickTurn);
    //m_pidController.SetReference(rotations, rev::ControlType::kPosition);
}

void DriveBase::DriveTank(float leftWheelInput, float rightWheelInput){

    m_robotDrive.TankDrive(leftWheelInput, rightWheelInput, false);
}
