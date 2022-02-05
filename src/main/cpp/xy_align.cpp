#include "xy_align.h"

using namespace frc;

void XYalign::test()
{
  float Kp = -0.1f;
  float KpDistance = -0.1f;

  float min_command = 0.05f;

  float targetYaw = table->GetNumber("targetYaw", 0.0);
  float targetPitch = table->GetNumber("targetPitch", 0.0);



    float heading_error =  180 - targetYaw;
    float distance_error = 120 - targetPitch;

    float steering_adjust = 0.0f;
    /*if (tx > 1.0)
    {
      steering_adjust = Kp*heading_error - min_command;
    }
    else if (tx < 1.0)
    {
      steering_adjust = Kp*heading_error + min_command;
    }*/
    float distance_adjust = KpDistance * distance_error; //Set the variable in shooter code
    steering_adjust = Kp*heading_error;

    ball_manage.target_velocity1 =  distance_adjust; 
    ball_manage.target_velocity2 =  distance_adjust;

    if(steering_adjust < 0.1 && steering_adjust > -0.1){
        ball_manage.Shoot();
    } 
    drivebase->DriveTank(steering_adjust, -steering_adjust);
  
}
bool XYalign::hasTargetLimeLight(){
  return table->GetBoolean("hasTarget", false);
}