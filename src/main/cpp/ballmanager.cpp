#include "ballmanager.h"
using namespace frc;

std::string BallManager::GetHopperState(int slot){
    if(slot != 0 && slot != 1){
        return "NULL";
    }
    else{
    return position[slot];
    }
}

void BallManager::CheckHopperState(){
    if(color_sensor.CheckForBall()){
        position[0] = color_sensor.ClosestColor();
    }
    if(ultrasonic.SonicDistance("in") > 3 && !color_sensor.CheckForBall() && position[0] != "None"){
        inbetween = position[0];
        position[0] = "None";
    }
    if(ultrasonic.SonicDistance("in") <= 3){
        position[1] = inbetween;
        inbetween = "None";
    }
    if(ultrasonic.SonicDistance("in") >3){
        position[1] = "None";
    }
}

void BallManager::MoveIndex()
{
    if(ultrasonic.SonicDistance("in") > 3 && position[0] != "None"){
        hopper.RunHopperMotor(0.5, 0.5);
    }
}

void BallManager::LoadHopper(){
    if(ultrasonic.SonicDistance("in") > 3){
        hopper.RunHopperMotor(0.5, 0.5);
    }
    else if(ultrasonic.SonicDistance("in") <= 3 && !color_sensor.CheckForBall()){
        hopper.RunHopperMotor(0, 0.5);
    }
}

bool BallManager::IsFull(){
    if(position[1] != "None" && position[0] != "None"){
        return !false;
    }
    else{
        return false;
    }
}

bool BallManager::Rev(double target_velocity_top, double target_velocity_bottom){  
    //if the ball in position[1] is the right color, shoot at the inputted velocities
    if (position[1] == team_color){
        shooter.VelocityControl(target_velocity_top, target_velocity_bottom);
        if(shooter.VelocityOutput("Top") >= target_velocity_top - MechanismConst::krange_target && 
            shooter.VelocityOutput("Top") <= target_velocity_top + MechanismConst::krange_target &&
            shooter.VelocityOutput("Bottom") >= target_velocity_bottom - MechanismConst::krange_target &&
            shooter.VelocityOutput("Bottom") <= target_velocity_bottom + MechanismConst::krange_target){
            return true;
        }
        else{
            return false;
        }
    }
    //if the ball in position[1] is not the right color shoot it at the reject velocity
    else if (position[1] != team_color){
        shooter.VelocityControl(MechanismConst::kreject_target, MechanismConst::kreject_target);

        if(shooter.VelocityOutput("Top") >= MechanismConst::kreject_target - MechanismConst::krange_reject  
        && shooter.VelocityOutput("Top") <= MechanismConst::kreject_target + MechanismConst::krange_reject
        && shooter.VelocityOutput("Bottom") <= MechanismConst::kreject_target + MechanismConst::krange_reject
        && shooter.VelocityOutput("Bottom") <= MechanismConst::kreject_target + MechanismConst::krange_reject){
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

void BallManager::Shoot(){
    hopper.RunHopperMotor(0.5, 0.5);
}

void BallManager::Reject(){
    shooter.VelocityControl(MechanismConst::kreject_target, MechanismConst::kreject_target);
    if(shooter.VelocityOutput("Top") >= MechanismConst::kreject_target - MechanismConst::krange_reject  
        && shooter.VelocityOutput("Top") <= MechanismConst::kreject_target + MechanismConst::krange_reject
        && shooter.VelocityOutput("Bottom") <= MechanismConst::kreject_target + MechanismConst::krange_reject
        && shooter.VelocityOutput("Bottom") <= MechanismConst::kreject_target + MechanismConst::krange_reject
        && position[1] != team_color){
        hopper.RunHopperMotor(0.5, 0);
    }
    if(position[0] != team_color){
        hopper.RunHopperMotor(0, -0.5);
        intake.RunIntake(-0.5);
    }
}
void DisplayBallManagerInfo(){
    if(BallManager::GetHopperState(0)=="None"){
        frc::Shuffleboard::GetTab("Telop").Add("Bottom None", True);
    }else if (BallManager::GetHopperState(0)=="Red"){
        frc::Shuffleboard::GetTab("Telop").Add("Bottom", GetHopperState(0));
    }else if (BallManager::GetHopperState(0)=="Blue")
    
}