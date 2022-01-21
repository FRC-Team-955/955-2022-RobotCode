#include "xy_align.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "drivebase.h"


using namespace frc;

void XYalign::test()
{
  float Kp = -0.1f;
  float min_command = 0.05f;

  auto table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
  float tx = table->GetNumber("tx", 0.0);

  if (joystick.GetRawButton(9))
  {
    float heading_error = -tx;
    float steering_adjust = 0.0f;
    /*if (tx > 1.0)
    {
      steering_adjust = Kp*heading_error - min_command;
    }
    else if (tx < 1.0)
    {
      steering_adjust = Kp*heading_error + min_command;
    }*/
    steering_adjust = Kp*heading_error;

    drivebase->DriveTank(steering_adjust, -steering_adjust);
  }
}