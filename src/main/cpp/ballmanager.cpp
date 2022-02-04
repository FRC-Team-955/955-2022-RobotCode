#include "ballmanager.h"
using namespace frc;

std::string BallManager::GetHopperState(int slot)
{
    if(slot != 0 && slow != 1)
    {
        return "NULL"
    }
    else
    {
    return position[slot];
    }
}

void BallManager::CheckHopperState()
{
    if(color_sensor.CheckForBall())
    {
        position[0] = color_sensor.ClosestColor();
    }
    if(!ultrasonic.SonicDistance("in") <= 3 && !color_sensor.CheckForBall() && position[0] != "NULL")
    {
        inbetween = position[0];
        position[0] = "NULL";
    }
    if(ultrasonic.SonicDistance("in") <= 3)
    {
        position[1] = inbetween;
        inbetween = "NULL";
    }
}

void BallManager::MoveIndex()
{
    if(!ultrasonic.SonicDistance("in") <= 3 && position[0] != "NULL")
    {
        hopper.RunHopperMotor(0.5, 0.5);
    }
}

void BallManager::LoadHopper()
{

    if(!ultrasonic.SonicDistance("in") <= 3)
    {
        hopper.RunHopperMotor(0.5, 0.5);
    }
    else if(ultrasonic.SonicDistance("in") <= 3 && !color_sensor.CheckForBall())
    {
        hopper.RunHopperMotor(0, 0.5);
    }
}

bool BallManager::IsEmpty()
{
    if(position[1] == "NULL" && position[0] == "NULL" && inbetween == "NULL"){
        return 1;
    }
    else{
        return 0;
    }
}

bool BallManager::Rev()

    if(shooter.ShootAtVelocity(motor_velocity) >= target_velocity - range && shooter.ShootAtVelocity(motor_velocity) <= target_velocity + range && position[1] == team_color){
        return 1;
    }
    else{
        return 0;
    }
}

void BallManager::Shoot()
{
    if(Rev())
    {
        hopper.RunHopperMotor(0.5, 0);
    }
}

void BallManager::Reject()
{
    if(shooter.ShootAtVelocity(MechanismConst::kreject_velocity) >= MechanismConst::kreject_target - range  && shooter.ShootAtVelocity(MechanismConst::kreject_velocity) <= MechanismConst::kreject_target + range && position[1] != team_color)
    {
        hopper.RunHopperMotor(0.5, 0);
    }
    if(position[0] != team_color)
    {
        hopper.RunHopperMotor(0, -0.5);
    }
}