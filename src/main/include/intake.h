#ifndef INTAKE
#define INTAKE
#include <frc/Solenoid.h>
#include <frc/Joystick.h>
#include <ctre/Phoenix.h>
#include <frc/Timer.h>
using namespace frc;

class Intake{
    public:

void intake_run();

    private:
    int stage = 0;
    float intake1 = 0.3;
    Timer time1{};
    Joystick joy1{1};
    TalonSRX t1{2};
    TalonSRX t2{3};
    Solenoid sol1{PneumaticsModuleType::CTREPCM , 0};
    Solenoid sol2{PneumaticsModuleType::CTREPCM , 1};
};


#endif