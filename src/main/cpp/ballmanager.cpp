#include "ballmanager.h"
using namespace frc;

std::string BallManager::GetHopperState(int position)
{
if(CheckForBall())
    {
    ball[0] = ClosestColor();
    }
if(!BeamBroken() && ball[0] != "NULL" && !CheckForBall())
    {
    inbetween = ball[0];
    ball[0] = "NULL"
    }
if(BeamBroken())
    {
    ball[1] = inbetween;
    }

if(position == 1())
    {
    return ball[0];
    }   
else if(position == 2 && BeamBroken())
    {
    return ball[1]
    }

}


void BallManager::Shoot()
{

}

bool BallManager::MoveIndex(int start, int end)
{

}