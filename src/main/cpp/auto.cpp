#include "auto.h"

frc::Rotation2d Auto::GetHeading(){
    return frc::Rotation2d(units::radian_t(-gyro.GetAngle()));
}

void Auto::UpdateOdometry(){
    pose = odometry.Update(GetHeading(),
    m_leftLeadMotor.GetEncoder().GetPosition() * AutoConst::kwheel_diameter_meters*M_PI / (24 * AutoConst::kgear_ratio),
    m_rightLeadMotor.GetEncoder().GetPosition() *AutoConst::kwheel_diameter_meters*M_PI / (24 * AutoConst::kgear_ratio));
}