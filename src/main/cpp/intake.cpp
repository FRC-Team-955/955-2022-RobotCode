#include "intake.h"
#include "units/time.h"
using namespace frc;

void Intake::intake_run(){
if(joy1.GetRawButton(1) == true){
    sol1.Set(1);
    sol2.Set(1);
} 
else if(joy1.GetRawButton(2) == true){
    sol1.Set(0);
    sol2.Set(0);
}

if(joy1.GetRawButton(3) == true){
    t1.Set(ControlMode::PercentOutput, intake1);
    if(t1.GetOutputCurrent() > 10){
       intake1 = !intake1;
       time1.Start();
    }
    if(time1.HasElapsed(units::second_t (0.5))){
    intake1 = !intake1;
    }
}
else if(joy1.GetRawButton(3) == false){
    t1.Set(ControlMode::PercentOutput, 0);
}
if(joy1.GetRawButton(4) == true){
    t1.Set(ControlMode::PercentOutput, .1);
    time1.Start();
    stage++;
}   if(stage == 1){
        if(time1.HasElapsed(units::second_t (2))){
        t1.Set(ControlMode::PercentOutput, 0);
        time1.Reset();
        stage = 0;
        }
    }
}
