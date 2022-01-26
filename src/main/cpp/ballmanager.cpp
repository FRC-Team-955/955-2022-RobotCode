#include "ballmanager.h"
using namespace frc;

std::string BallManager::GetHopperState(int slot)
{
    return position[slot - 1];
}

void BallManager::CheckHopperState()
{
    if(CheckForBall())
    {
        position[0] = ClosestColor();
    }
    if(!BeamBroken() && !CheckForBall() && position[0] != "NULL")
    {
        inbetween = position[0];
        
    }
    if(BeamBroken())
    {
        position[1] = inbetween;
        position[0] = "NULL";
    }
    if(!BeamBroken())
    {
        positition[1] = "NULL";
    }
}

bool BallManager::MoveIndex()
{
    if(!BeamBroken() && position[0] != "NULL")
    {
        RunHopperMotor(0.5, 0);
    }
}

void BallManager::LoadHopper()
{
    if(IsEmpty())
    {
        RunHopperMotor(0.5, 0.5);
    }
    if(BeamBroken() && !CheckForBall())
    {
        RunHopperMotor(0, 0.5);
    }
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