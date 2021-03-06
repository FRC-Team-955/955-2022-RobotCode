#ifndef HOPPER
#define HOPPER
#include "settings.h"
#include <ctre/Phoenix.h>

using namespace frc;

class Hopper {
public:
  void RunHopperMotor(int hopper_motor_top_percent, int hopper_motor_bottom_percent);
  int max_percent = 1;
private:
  TalonSRX talon_hopper_top{MechanismConst::khopper_motor_top_port};
  TalonSRX talon_hopper_bottom{MechanismConst::khopper_motor_bottom_port};
};

#endif