#include "Motortester.h"
#include "units/time.h"
using namespace frc;

void Motor::motor_test(){
    time.Start();
    if (joy1.GetRawButtonPressed(1) == true){
        time.Reset();
        if (stage == 1){
            motor1.Set(ControlMode::PercentOutput, 0.1);
            if (time.HasElapsed(units::second_t (3)) == true){
                motor1.Set(ControlMode::PercentOutput, 0);
                time.Reset();
                stage++;
            }
        }
        if (stage == 2){
            motor2.Set(ControlMode::PercentOutput, 0.1);
            if (time.HasElapsed(units::second_t (3)) == true){
                motor2.Set(ControlMode::PercentOutput, 0);
                time.Reset();
                stage++;
            }
             
        }

        if (stage == 3){
            motor3.Set(ControlMode::PercentOutput, 0.1);
            if (time.HasElapsed(units::second_t (3)) == true){
                motor3.Set(ControlMode::PercentOutput, 0);
                time.Reset();
                stage++;
            }
        
        }

        if (stage == 4){
            motor4.Set(ControlMode::PercentOutput, 0.1);
            if (time.HasElapsed(units::second_t (3)) == true){
                motor4.Set(ControlMode::PercentOutput, 0);
                time.Reset();
                stage++;
            }
             
        }

        if (stage == 5){
            motor5.Set(ControlMode::PercentOutput, 0.1);
            if (time.HasElapsed(units::second_t (3)) == true){
                motor5.Set(ControlMode::PercentOutput, 0);
                time.Reset();
                stage++;
            }
             
        }
    
        if (stage == 6){
            motor6.Set(ControlMode::PercentOutput, 0.1);
            if (time.HasElapsed(units::second_t (3)) == true){
                motor6.Set(ControlMode::PercentOutput, 0);
                time.Reset();
                stage++;
            }
             
        }

        if (stage == 7){
            motor7.Set(ControlMode::PercentOutput, 0.1);
            if (time.HasElapsed(units::second_t (3)) == true){
                motor7.Set(ControlMode::PercentOutput, 0);
                time.Reset();
                stage++;
            }
             
        }

        if (stage == 8){
            motor8.Set(ControlMode::PercentOutput, 0.1);
            if (time.HasElapsed(units::second_t (3)) == true){
                motor8.Set(ControlMode::PercentOutput, 0);
                time.Reset();
                stage++;
            }
        }
    }
}