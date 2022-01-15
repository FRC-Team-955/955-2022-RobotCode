#ifndef INTAKE
#define INTAKE
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <ctre/Phoenix.h>
using namespace frc;

class Intake {
    public:
        
        void intake_run();
    
    private:
    Joystick j1{1};
    TalonSRX t1{1};
    Solenoid s2{PneumaticsModuleType::CTREPCM , 0};
    Solenoid s1{PneumaticsModuleType::CTREPCM , 1};
};

#endif