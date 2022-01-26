#include "ballmanager.h"
using namespace frc;

std::string BallManager::GetHopperState(int slot)
{
    return position[slot - 1];
}

void BallManager::CheckHopperState()
{
    if(color_sensor.CheckForBall())
    {
        position[0] = color_sensor.ClosestColor();
    }
    if(!break_beam.BeamBroken() && !color_sensor.CheckForBall() && position[0] != "NULL")
    {
        inbetween = position[0];
        position[0] = "NULL";
    }
    if(break_beam.BeamBroken())
    {
        position[1] = inbetween;
    }
}

void BallManager::MoveIndex()
{
    if(!break_beam.BeamBroken() && position[0] != "NULL")
    {
        hopper.RunHopperMotor(0.5, 0);
    }
}

void BallManager::LoadHopper()
{
    if(IsEmpty())
    {
        hopper.RunHopperMotor(0.5, 0.5);
    }
    if(break_beam.BeamBroken() && !color_sensor.CheckForBall())
    {
        hopper.RunHopperMotor(0, 0.5);
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

void BallManager::Shoot()
{
    if(shooter.ShootAtVelocity(10000) >= 1000 && position[1] == team_color)
    {
        shooter.ShootAtVelocity(1000);
        position[1] = "NULL";
    }
    else if(shooter.ShootAtVelocity(10000) >= 100 && position[1] != team_color)
    {
        shooter.ShootAtVelocity(100);
        position[1] = "NULL";
    }
}
