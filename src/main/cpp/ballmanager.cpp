#include "ballmanager.h"
using namespace frc;

std::string BallManager::GetHopperState(int slot)
{
    return position[slot - 1];
}

void BallManager::CheckHopperState()
{
    if(IsEmpty())
    {
        RunHopperMotor(0.5, 0.5);
    }
    if(CheckForBall)
    {
        position[0] = ClosestColor();
    }
}

bool BallManager::MoveIndex(int start, int end)
{

}

void BallManager::LoadHopper()
{

}

bool BallManager::IsEmpty()
{
    if(position[1] == "NULL" && position[0] == "NULL"){
        return 1;
    }
    else{
        return 0;
    }
}