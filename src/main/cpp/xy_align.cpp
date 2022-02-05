#include "xy_align.h"

using namespace frc;

void XYalign::Align()
{
  float Kp = -0.1;
  float KpDistance = -0.1;

  float min_command = 0.05;

  float targetYaw = table->GetNumber("targetYaw", 0.0);
  float targetPitch = table->GetNumber("targetPitch", 0.0);



  float heading_error =  targetYaw;
  float distance_error = targetPitch;

  float steering_adjust = 0.0f;
    if (Kp*heading_error > 0)
    {
      steering_adjust = std::max(Kp*heading_error - min_command)
    }
    else if (Kp*heading_error <= 0)
    {
      steering_adjust = std::min(Kp*heading_error, min_command);
    }
    float distance_adjust = KpDistance * distance_error; //Set the variable in shooter code

    ball_manage.target_velocity1 =  distance_adjust; 
    ball_manage.target_velocity2 =  distance_adjust;

    ball_manage.Rev();
    if(steering_adjust < 0.1 && steering_adjust > -0.1){
        ball_manage.Shoot();
    } 
    drivebase->DriveTank(steering_adjust, -steering_adjust);
  
}
bool XYalign::HasTargetLimeLight(){
  return table->GetBoolean("hasTarget", false);
}