#include "auto.h"

frc::Rotation2d Auto::GetHeading(){
    //has neg cause nevx returns pos values for clockwise, but for unit circles clock is neg
    return frc::Rotation2d(units::radian_t(-gyro.GetAngle()));
}

frc::DifferentialDriveWheelSpeeds Auto::GetSpeeds(){
    //GetVelocity is in rpm and you need to convert to meters per sec(no false might have been updated)
    //It actually returns volts per sec actually nvm it does return rpm documentation is a lie I think
    wheelsSpeeds.left =  m_leftLeadMotor.GetEncoder().GetVelocity() / AutoConst::kgear_ratio *AutoConst::kwheel_diameter_meters *M_PI / 60;
    wheelsSpeeds.right =  m_rightLeadMotor.GetEncoder().GetVelocity() / AutoConst::kgear_ratio *AutoConst::kwheel_diameter_meters *M_PI / 60;
    return wheelsSpeeds;

    // m_leftLeadMotor.GetEncoder().GetVelocity() *(AutoConst::kwheel_diameter_meters* M_PI) / (AutoConst::kgear_ratio*60),
    // m_rightLeadMotor.GetEncoder().GetVelocity() *(AutoConst::kwheel_diameter_meters *M_PI) / (AutoConst::kgear_ratio*60)

}

frc::Pose2d Auto::UpdateOdometry(){
    pose = odometry.Update(GetHeading(),
    m_leftLeadMotor.GetEncoder().GetPosition() * AutoConst::kwheel_diameter_meters*M_PI / (24 * AutoConst::kgear_ratio),
    m_rightLeadMotor.GetEncoder().GetPosition() *AutoConst::kwheel_diameter_meters*M_PI / (24 * AutoConst::kgear_ratio));
    return pose;
}

void Auto::GenerateTrajectory(){
    //just as a test makes a trajectory from 0,0(no heading) to 1,0(no heading still)
    trajectory = trajectoryGenerator.GenerateTrajectory(frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),{frc::Translation2d(0.5_m, 0_m)}, frc::Pose2d(1_m,0_m, frc::Rotation2d(0_deg)),config);
}

void Auto::SetOutput(double leftVolts,double rightVolts){
    // m_leftLeadMotor.SetVoltage(leftVolts);
    // m_rightLeadMotor.SetVoltage(rightVolts);

    //Set takes in -1 to 1, volts is between -12 to 12
    m_leftLeadMotor.Set(leftVolts/12);
    m_rightLeadMotor.Set(rightVolts/12);
}