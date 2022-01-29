#ifndef INTAKE
#define INTAKE
#include <frc/Solenoid.h>
#include <frc/Joystick.h>
#include <ctre/Phoenix.h>
#include <frc/Timer.h>
using namespace frc;

class Intake{
public:
    Intake(){
        t1.TalonSRX::ConfigPeakCurrentLimit(40);
        t1.TalonSRX::EnableCurrentLimit(true);
    }
    void intake_run();
    void PistonUp();
    void PistonDown();
    void RunIntake();
    void StopIntake();
private:
    int stage = 0;
    float intake1 = 0.3;
    Timer time1{};
    Joystick joy1{1};
    TalonSRX t1{2};
    Solenoid sol1{PneumaticsModuleType::CTREPCM , 0};
    Solenoid sol2{PneumaticsModuleType::CTREPCM , 1};
};


#endif