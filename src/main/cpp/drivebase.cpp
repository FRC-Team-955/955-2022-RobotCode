#include "drivebase.h"

void DriveBase::Drive() {
  bool isQuickTurn = joystick.GetRawButton(Joy0Const::kquick_turn_button);

  if (joystick.GetRawButtonPressed(Joy0Const::kreverse_drive)) {
    ReverseDrive = !ReverseDrive;
  }
  if (ReverseDrive == false) {
    m_robotDrive.CurvatureDrive(
        joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        joystick.GetRawAxis(Joy0Const::kquick_turn_button), isQuickTurn);
    // frc::SmartDashboard::PutBoolean("Reverse Drive", ReverseDrive);

  } else {
    m_robotDrive.CurvatureDrive(
        -joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        -joystick.GetRawAxis(Joy0Const::kquick_turn_button), isQuickTurn);
    // frc::SmartDashboard::PutBoolean("Reverse Drive", ReverseDrive);
  }

  // m_pidController.SetReference(rotations, rev::ControlType::kPosition);
}

void DriveBase::DisplayDriveInfo() {
  
  frc::Shuffleboard::GetTab("Telop").Add("LeftLeadAmps", m_leftLeadMotor.GetOutputCurrent());
  frc::Shuffleboard::GetTab("Telop").Add("leftFollowMotor", m_leftFollowMotor.GetOutputCurrent());
  frc::Shuffleboard::GetTab("Telop").Add("rightLeadMotor",m_rightLeadMotor.GetOutputCurrent());
  frc::Shuffleboard::GetTab("Telop").Add("rightFollowMotor", m_rightFollowMotor.GetOutputCurrent());
  frc::Shuffleboard::GetTab("Telop").Add("Reverse Drive", ReverseDrive).WithWidget(frc::BuiltInWidgets::kBooleanBox);
}
// frc::ShuffleboardWidget::WithWidgets();
// void DriveBase::DriveBaseSpeed(int speedleft, int speedright, double number) {
//   number = 2*3.14159*0.1016/609; 
//   m_leftLeadMotor.SetVelocityConversionFactor(number);
//   GetVelocityConversionFactor();
//   speedleft= GetVelocity();
//   m_rightLeadMotor.SetVelocityConversionFactor(number)
//   GetVelocityConversionFactor();
//   speedright = GetVelocity(); 

// }