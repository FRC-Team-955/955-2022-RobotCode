#include "xy_align.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "drivebase.h"


using namespace frc;

void XYalign::test()
{
  float Kp = -0.1f;
  float KpDistance = -0.1f;

  float min_command = 0.05f;

  auto table = nt::NetworkTableInstance::GetDefault().GetTable("photonvision");
  float targetYaw = table->GetNumber("targetYaw", 0.0);
  float targetPitch = table->GetNumber("targetPitch", 0.0);


  if (joystick.GetRawButton(9))
  {
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

    drivebase->DriveTank(steering_adjust, -steering_adjust);
  }
}