#ifndef HOPPER
#define HOPPER
#include <ctre/Phoenix.h>
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
        TalonSRX talon_hopper_top{MechanismConst::khopper_motor_number1};
        TalonSRX talon_hopper_bottom{MechanismConst::khopper_motor_number2};
};

#endif