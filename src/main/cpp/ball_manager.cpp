#include "ball_manager.h"

std::string BallManager::GetHopperState(int position){
    if(CheckForBall() == true && Ball2[1] != "Position 2" && Ball1[1] != "Position 2"){
            Ball1[0] = ClosestColor();
    }
    if(BeamBroken() == true){
        Ball1[1] = "Position 2";
    }
    if(CheckForBall() == true && Ball1[1] == "Position 2"){
        Ball2[0] = ClosestColor();    
        Ball2[1] = "Position 1";
    }

    if (position == 1){
        return Ball2[0];
    } else if (position == 2){
        return Ball1[0];
    }
}

void BallManager::ShootBall(){

}

bool BallManager::MovePosition(0, 1)
