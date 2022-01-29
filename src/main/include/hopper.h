#ifndef HOPPER
#define HOPPER
#include "settings.h"
#include <algorithm>
using namespace frc;

class Hopper{
    public:
        Hopper(){
            talon_hopper_top.TalonSRX::ConfigPeakCurrentLimit(40);
            talon_hopper_bottom.TalonSRX::ConfigPeakCurrentLimit(40);
            talon_hopper_top.TalonSRX::EnableCurrentLimit(true);
            talon_hopper_bottom.TalonSRX::EnableCurrentLimit(true);
        }
        int max = 1;
        void Run_Hopper_Motor(int hopper_motor_percent_top, int hopper_motor_percent_bottom);
    private:
        TalonSRX talon_hopper_top{MechanismConst::khopper_motor_top_port};
        TalonSRX talon_hopper_bottom{MechanismConst::khopper_motor_bottom_port};
};

#endif