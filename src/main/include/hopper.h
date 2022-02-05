#ifndef HOPPER
#define HOPPER
#include "settings.h"
#include <algorithm>
#include <ctre/Phoenix.h>

class Hopper {
public:
  Hopper() {
    talon_hopper_top.TalonSRX::ConfigPeakCurrentLimit(40);
    talon_hopper_bottom.TalonSRX::ConfigPeakCurrentLimit(40);
    talon_hopper_top.TalonSRX::EnableCurrentLimit(true);
    talon_hopper_bottom.TalonSRX::EnableCurrentLimit(true);
  }
  int max = 1;
  void RunHopperMotor(int hopper_motor_percent_top,
                      int hopper_motor_percent_bottom);
  void DiplayHopperInfo();
private:
  TalonSRX talon_hopper_top{MechanismConst::khopper_motor_top_port};
  TalonSRX talon_hopper_bottom{MechanismConst::khopper_motor_bottom_port};
};
#endif
