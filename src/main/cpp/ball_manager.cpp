#include "ball_manager.h"


int BallManager::GetBallColor(){
    /*GetColor();
    if (GetColor() == "red"){
        return 1;
    } else if (GetColor() == "blue"){
        return 0;
    }*/
    return 0;
}

void BallManager::ShootBalls(){
    //ShootAtVelocity() = set_velocity;
    if (set_velocity > set_velocity - MechanismConst::kvelocity_range && set_velocity <  set_velocity + MechanismConst::kvelocity_range){
        shooter_motor.Set(ControlMode::Velocity, set_velocity);
    }
}