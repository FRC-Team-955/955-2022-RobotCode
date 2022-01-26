#ifndef HOPPER
#define HOPPER
#include "settings.h"
#include <ctre/Phoenix.h>
#include <frc/shuffleboard/Shuffleboard.h>

using namespace frc;

class Hopper {
public:
  void RunHopperMotor(int hopper_motor_top_percent, int hopper_motor_bottom_percent);
  void HopperAmp(int amp1, int amp2);
  void HopperBall(int color, int location);
  void BreakBeam(int read);
  int max_percent = 1;
private: 
  TalonSRX talon_hopper_top{MechanismConst::khopper_motor_top_port};
  TalonSRX talon_hopper_bottom{MechanismConst::khopper_motor_bottom_port};
};

#endif