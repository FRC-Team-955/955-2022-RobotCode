#include "drivebase.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "iostream"
void DriveBase::Drive() {
  bool isQuickTurn = joystick.GetRawButton(Joy0Const::kquick_turn_button);
  
  if (joystick.GetRawButtonPressed(Joy0Const::kreverse_drive)) {
    ReverseDrive = !ReverseDrive;
    std::cout<<"swtich"<<std::endl;
  }
  if (ReverseDrive == false) {
    m_robotDrive.CurvatureDrive(
        joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        joystick.GetRawAxis(Joy0Const::kquick_turn_button), isQuickTurn);
    frc::SmartDashboard::PutBoolean("Reverse Drive", ReverseDrive);
    std::cout<<"uhh rev drive is false"<<std::endl;

  } else {
    m_robotDrive.CurvatureDrive(
        -joystick.GetRawAxis(Joy0Const::kdrive_speed_axis),
        -joystick.GetRawAxis(Joy0Const::kquick_turn_button), isQuickTurn);
    frc::SmartDashboard::PutBoolean("Reverse Drive", ReverseDrive);
    std::cout<<"uhh rev drive is true"<<std::endl;
  }

  // m_pidController.SetReference(rotations, rev::ControlType::kPosition);
}
