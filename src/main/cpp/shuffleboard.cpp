#include "shuffleboard.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>

void ShuffleBoard::UpdateShuffleBoard(){
    Shuffleboard::GetTab("Telop").Add("LeftLeadAmps", (drivebase->DriveBaseAmp())[0]);
  Shuffleboard::GetTab("Telop").Add("leftFollowMotor", (drivebase->DriveBaseAmp())[1]);
  Shuffleboard::GetTab("Telop").Add("rightLeadMotor", (drivebase->DriveBaseAmp())[2]);
  Shuffleboard::GetTab("Telop").Add("rightFollowMotor", (drivebase->DriveBaseAmp())[3]);
}