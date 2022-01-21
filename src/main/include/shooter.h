#ifndef SHOOTER
#define SHOOTER
#include <iostream>
#include "frc/Joystick.h"
#include "ctre/Phoenix.h"
using namespace frc;

class Shooter {
    Shooter(){}
    public:
    float ShootAtVelocity(int velocity);
    void ShootPercentOutput(int percent);


    private:
    TalonSRX shootertalon_lead {1};

};

#endif
