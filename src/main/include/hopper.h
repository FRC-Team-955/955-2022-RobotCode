#ifndef HOPPER
#define HOPPER
#include <ctre/Phoenix.h>
#include "settings.h"
using namespace frc;

class Hopper{
    public:
        void Run_Hopper_Motor(int percent);
    private:
        TalonSRX talon_hopper{MechanismConst::khopper_motor_number};
        int percent;
};

#endif