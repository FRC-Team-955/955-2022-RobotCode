#ifndef OMNIDRIVE
#define OMNIDRIVE
#include <iostream>
#include <frc/drive/DifferentialDrive.h>
using namespace frc;
#include "settings.h"
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>

class Omnidrive {
public:
  Omnidrive (Joystick *joy, TalonSRX *leftLeadMotor, TalonSRX *rightLeadMotor, TalonSRX *leftFollowerMotor, TalonSRX *rightFollowerMotor) : joy(joy), leftLeadMotor(leftLeadMotor), rightLeadMotor(rightLeadMotor), leftFollowerMotor(leftFollowerMotor), rightFollowerMotor(rightFollowerMotor) {};
  double right;
  double left;
  void Drive();
private:
  Joystick *joy;
  TalonSRX *leftLeadMotor;
  TalonSRX *rightLeadMotor;
  TalonSRX *leftFollowerMotor;  
  TalonSRX *rightFollowerMotor;
  
};
#endif