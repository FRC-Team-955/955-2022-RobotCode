#include "intake.h"
#include "units/time.h"
using namespace frc;

/*void Intake::intake_run(){
if(joy1.GetRawButton(1) == true){
    sol1.Set(1);
    sol2.Set(1);
}
else if(joy1.GetRawButton(2) == true){
    sol1.Set(0);
    sol2.Set(0);
}

if(joy1.GetRawButton(3) == true){
    intake_talon.Set(ControlMode::PercentOutput, intake_percent);
    if(intake_talon.GetOutputCurrent() > 10){
       intake_percent = !intake_percent;
       timer.Start();
    }
    if(timer.HasElapsed(units::second_t (0.5))){
    intake_percent = !intake_percent;
    }
}
else if(joy1.GetRawButton(3) == false){
    intake_talon.Set(ControlMode::PercentOutput, 0);
}
if(joy1.GetRawButton(4) == true){
    intake_talon.Set(ControlMode::PercentOutput, .1);
    timer.Start();
    stage++;
}   if(stage == 1){
        if(timer.HasElapsed(units::second_t (2))){
        intake_talon.Set(ControlMode::PercentOutput, 0);
        timer.Reset();
        stage = 0;
        }
    }
}
*/

void Intake::PistonUp() {
  sol1.Set(1);
  sol2.Set(1);
}

void Intake::PistonDown() {
  sol1.Set(0);
  sol2.Set(0);
}

void Intake::RunIntake() {
  intake_talon.Set(ControlMode::PercentOutput, intake_percent);
  if (intake_talon.GetOutputCurrent() > 10) {
    intake_percent *= -1;
    timer.Start();
  }
  if (timer.HasElapsed(units::second_t(0.5))) {
    intake_percent *= -1;
  }
}

void Intake::StopIntake() { intake_talon.Set(ControlMode::PercentOutput, 0); }
