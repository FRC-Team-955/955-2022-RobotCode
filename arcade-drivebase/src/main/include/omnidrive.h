#ifndef OMNIDRIVE
#define OMNIDRIVE
#include <iostream>
#include <frc/drive/DifferentialDrive.h>
using namespace frc;
#include "settings.h"
#include <ctre/Phoenix.h>

class Omnidrive {
public:
  Omnidrive() {
  }
private:
  TalonSRX leftLeadMotor {MechanismConst::khopper_motor_left_lead_port};
  TalonSRX rightLeadMotor {MechanismConst::khopper_motor_right_lead_port};
  TalonSRX leftFollowerMotor {MechanismConst::khopper_motor_left_follower_port};  
  TalonSRX rightFollowerMotor {MechanismConst::khopper_motor_right_follower_port};
  DifferentialDrive differential_drive {leftLeadMotor, rightLeadMotor};
  
};
#endif