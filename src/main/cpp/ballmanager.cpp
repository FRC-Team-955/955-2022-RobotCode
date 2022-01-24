#include "ballmanager.h"
using namespace frc;

std::string BallManager::GetHopperState(int slot)
{
    return position[slot - 1];
}


void BallManager::Shoot()
{

}

bool BallManager::MoveIndex(int start, int end)
{

}

void BallManager::LoadHopper()
{

}

bool BallManager::IsEmpty()
{
    if(position[1] == "NULL" && position[0] == "NULL")
}