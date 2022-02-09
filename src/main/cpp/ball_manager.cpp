#include "ballmanager.h"
using namespace frc;

std::string BallManager::GetHopperState(int slot)
{
    if(slot != 0 && slot != 1)
    {
        return "NULL";
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
    if(ultrasonic.SonicDistance("in") > 3 && !color_sensor.CheckForBall() && position[0] != "NULL")
    {
        inbetween = position[0];
        position[0] = "NULL";
    }
    if(ultrasonic.SonicDistance("in") <= 3)
    {
        position[1] = inbetween;
        inbetween = "NULL";
    }
    if(ultrasonic.SonicDistance("in") >3)
    {
        position[1] = "Null";
    }
}

void BallManager::MoveIndex()
{
    if(ultrasonic.SonicDistance("in") > 3 && position[0] != "NULL")
    {
        hopper.RunHopperMotor(0.5, 0.5);
    }
}

void BallManager::LoadHopper()
{
    if(ultrasonic.SonicDistance("in") > 3)
    {
        hopper.RunHopperMotor(0.5, 0.5);
    }
    else if(ultrasonic.SonicDistance("in") <= 3 && !color_sensor.CheckForBall())
    {
        hopper.RunHopperMotor(0, 0.5);
    }
}

bool BallManager::IsFull()
{
    if(position[1] !== "NULL" && position[0] !== "NULL"){
        return !false;
    }
    else{
        return false;
    }
}

bool BallManager::Rev(double target_velocity)
{   
    if (position[1] == team_color){
        if(shooter.ShootAtVelocity(target_velocity, target_velocity) >= target_velocity - MechanismConst::krange_target && shooter.ShootAtVelocity(target_velocity, target_velocity) <= target_velocity + MechanismConst::krange_target){
            return true;
        }
        else{
            return false;
        }
    }
    else if (position[1] != team_color){
        if(shooter.ShootAtVelocity(MechanismConst::kreject_target, MechanismConst::kreject_target) >= MechanismConst::kreject_target - MechanismConst::krange_reject  
        && shooter.ShootAtVelocity(MechanismConst::kreject_target, MechanismConst::kreject_target) <= MechanismConst::kreject_target + MechanismConst::krange_reject){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void BallManager::Shoot()
{
    hopper.RunHopperMotor(0.5, 0.5);
}

void BallManager::Reject()
{
    if(shooter.ShootAtVelocity(MechanismConst::kreject_target, MechanismConst::kreject_target) >= MechanismConst::kreject_target - MechanismConst::krange_reject && 
        shooter.ShootAtVelocity(MechanismConst::kreject_target, MechanismConst::kreject_target) <= MechanismConst::kreject_target + MechanismConst::krange_reject && 
        position[1] != team_color)
    {
        hopper.RunHopperMotor(0.5, 0);
    }
    if(position[0] != team_color)
    {
        hopper.RunHopperMotor(0, -0.5);
        intake.RunIntake(-0.5)
    }
}