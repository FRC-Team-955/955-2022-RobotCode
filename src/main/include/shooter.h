#ifndef SHOOTER
#define SHOOTER
#include <iostream>
#include "frc/Joystick.h"
#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"
using namespace frc;

class Shooter {
    Shooter(){
        shooterneo_lead.SetSmartCurrentLimit(40); 
        shooterneo_follow.SetSmartCurrentLimit(40);
        }
    public:
    float ShootAtVelocity(int velocity);
    void ShootPercentOutput(int percent);
    void IndependentControl(int leadvelocity, int followvelocity);


    private:
    rev::CANSparkMax shooterneo_lead {DriveConst::kright_lead_neo_number, CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax shooterneo_follow {DriveConst::kright_lead_neo_number, CANSparkMax::MotorType::kBrushless};


};

#endif
