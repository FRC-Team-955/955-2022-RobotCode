#ifndef SHOOTER
#define SHOOTER
#include <iostream>
#include "frc/Joystick.h"
#include "ctre/Phoenix.h"
using namespace std;
using namespace frc;

class Shooter {
    Shooter(){shootertalon_follow.SetInverted(1);}
    public:
    float ShootAtVelocity(int Velocity);
    void ShootPercentOutput(int Percent);
    float IndependentControl(int VelocityLead, int VelocityFollow);


    private:
    TalonSRX shootertalon_lead {1};
    TalonSRX shootertalon_follow {2};
};

#endif
