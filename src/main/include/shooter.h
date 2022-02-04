#ifndef SHOOTER
#define SHOOTER
#include <iostream>
#include "frc/Joystick.h"
#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"
#include "settings.h"
using namespace rev;

class Shooter {
    Shooter(){
        shooterneo_lead.SetSmartCurrentLimit(40); 
        shooterneo_follow.SetSmartCurrentLimit(40);
        
        m_pidController.SetP(MechanismConst::kP);
        m_pidController.SetI(MechanismConst::kI);
        m_pidController.SetD(MechanismConst::kD);
        m_pidController.SetIZone(MechanismConst::kIz);
        m_pidController.SetFF(MechanismConst::kFF);
        m_pidController.SetOutputRange(MechanismConst::kMinOutput, MechanismConst::kMaxOutput);
        
        m_pidController2.SetP(MechanismConst::kP);
        m_pidController2.SetI(MechanismConst::kI);
        m_pidController2.SetD(MechanismConst::kD);
        m_pidController2.SetIZone(MechanismConst::kIz);
        m_pidController2.SetFF(MechanismConst::kFF);
        m_pidController2.SetOutputRange(MechanismConst::kMinOutput, MechanismConst::kMaxOutput);
        
        }
    public:
    void ShootPercentOutput(int percent);
    void IndependentControl(int leadvelocity, int followvelocity);


    private:
    rev::CANSparkMax shooterneo_lead {1, CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax shooterneo_follow {2, CANSparkMax::MotorType::kBrushless};
    rev::SparkMaxPIDController m_pidController = shooterneo_lead.GetPIDController();
    rev::SparkMaxPIDController m_pidController2 = shooterneo_follow.GetPIDController();


};

#endif
