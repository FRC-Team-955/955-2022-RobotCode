#ifndef HOPPER
#define HOPPER
#include <ctre/Phoenix.h>
#include "settings.h"
using namespace frc;

class Hopper{
    public:
        void Run_Hopper_Motor(int hopper_motor_percent1, int hopper_motor_percent2, int hopper_motor_percent3);
        int hopper_motor_percent1 = 1;
        int hopper_motor_percent2 = 2;
        int hopper_motor_percent3 = 3;
    private:
        TalonSRX talon_hopper1{MechanismConst::khopper_motor_number1};
        TalonSRX talon_hopper2{MechanismConst::khopper_motor_number2};
        TalonSRX talon_hopper3{MechanismConst::khopper_motor_number3};
};

#endif