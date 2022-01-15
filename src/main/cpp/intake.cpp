#include "intake.h"
using namespace frc;

void Intake::intake_run(){
    if(j1.GetRawButton(1) == true){
        s1.Set(1);
        s2.Set(1);
    } else if(j1.GetRawButton(2) == true){
        s2.Set(0);
        s1.Set(0);
    }
    
    if (j1.GetRawButton(3) == true){
        t1.Set(ControlMode::PercentOutput, .5);
        if(t1.GetOutputCurrent() > 10){
            t1.Set(ControlMode::PercentOutput, -.5);
        } 
    }

    else if(j1.GetRawButton(3) == 0){
            t1.Set(ControlMode::PercentOutput, 0);
        }
}

