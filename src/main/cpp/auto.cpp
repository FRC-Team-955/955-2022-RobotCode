#include "auto.h"

frc::Rotation2d Auto::GetHeading(){
    return frc::Rotation2d(units::radian_t(-gyro.GetAngle()));
}