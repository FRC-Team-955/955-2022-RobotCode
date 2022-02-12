#include "auto.h"


void Auto::Reset(){
    std::cout<<"this is cringe0"<<std::endl;
    std::cout<<"this is cringe"<<std::endl;

    m_leftFollowMotor.Follow(m_leftLeadMotor);
    m_rightFollowMotor.Follow(m_rightLeadMotor);
    std::cout<<"this is cringe2"<<std::endl;

    m_leftLeadMotor.SetInverted(false);
    m_rightLeadMotor.SetInverted(true);
    std::cout<<"this is cringe3"<<std::endl;

    m_leftLeadMotor.GetEncoder().SetPosition(0);
    m_rightLeadMotor.GetEncoder().SetPosition(0);
    std::cout<<"this is cringe4"<<std::endl;

    gyro.Reset();
    std::cout<<"this is cringe5"<<std::endl;

    config.SetKinematics(kinematics);
    std::cout<<"this is cringe6"<<std::endl;

}
void Auto::ResetOdometry(const frc::Pose2d& pose) {
    //You need to run Reset before this as Encoders need to be reset
    //resets the positions of the position
    odometry.ResetPosition(pose, GetHeading()); 
}

frc::Rotation2d Auto::GetHeading(){
    //has neg cause nevx returns pos values for clockwise, but for unit circles clock is neg
    return frc::Rotation2d(units::radian_t(-gyro.GetAngle()));
}
frc::Pose2d Auto::UpdateOdometry(){
    //updates the position of the pose of the robot via the odometry 
    //using the current angle of robot, total left distance (meter_t), total right distance (meter_t)
    pose = odometry.Update(GetHeading(),
    m_leftLeadMotor.GetEncoder().GetPosition() * AutoConst::kwheel_diameter_meters*M_PI / (24 * AutoConst::kgear_ratio),
    m_rightLeadMotor.GetEncoder().GetPosition() *AutoConst::kwheel_diameter_meters*M_PI / (24 * AutoConst::kgear_ratio));
    return pose;
}

void Auto::Drive(units::meters_per_second_t xSpeed, units::radians_per_second_t rot) {
    //ToWheelSpeeds returns the target left and right velocities which is converted into DifferentialDriveWheelSpeeds to input into SetSpeeds
  SetSpeeds(kinematics.ToWheelSpeeds({xSpeed, 0_mps, rot}));
}

void Auto::SetSpeeds(const frc::DifferentialDriveWheelSpeeds& speeds) {
    //using the target left and right speeds it outputs the volts needed
    const auto leftFeedforward = feedforward.Calculate(speeds.left);
    const auto rightFeedforward = feedforward.Calculate(speeds.right);

    //Sets the left and right pid correction values with the current velocity and the target velocity
    const double leftOutput = leftPIDController.Calculate(
        double(m_leftLeadMotor.GetEncoder().GetVelocity() / AutoConst::kgear_ratio *AutoConst::kwheel_diameter_meters *M_PI / 60), speeds.left.to<double>()); 
    const double rightOutput = rightPIDController.Calculate(
        double(m_rightLeadMotor.GetEncoder().GetVelocity() / AutoConst::kgear_ratio *AutoConst::kwheel_diameter_meters *M_PI / 60), speeds.right.to<double>()); 

    //Sets the voltage to the motors should be between -12V to 12V
    m_leftLeadMotor.SetVoltage(units::volt_t{leftOutput} + leftFeedforward);
    m_rightLeadMotor.SetVoltage(units::volt_t{rightOutput} + rightFeedforward);
}

void Auto::GenerateTrajectory(){
    std::cout<<"tewefst"<<std::endl;

    //just as a test makes a trajectory from 0,0(no heading) to 1,0(no heading still)
    trajectory = trajectoryGenerator.GenerateTrajectory(frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),{frc::Translation2d(0.5_m, 0_m)}, frc::Pose2d(1_m,0_m, frc::Rotation2d(0_deg)),config);
    std::cout<<"test"<<std::endl;
}

void Auto::SetTrajectory(frc::Trajectory trajectory_input){
    std::cout<<"uh in fun"<<std::endl;
    trajectory= trajectory_input;
    std::cout<<"uh in fun after"<<std::endl;

}

// void Auto::SetOutput(double leftVolts,double rightVolts){
//     // m_leftLeadMotor.SetVoltage(leftVolts);
//     // m_rightLeadMotor.SetVoltage(rightVolts);

//     //Set takes in -1 to 1, volts is between -12 to 12
//     m_leftLeadMotor.Set(leftVolts/12);
//     m_rightLeadMotor.Set(rightVolts/12);
// }
// frc::DifferentialDriveWheelSpeeds Auto::GetSpeeds(){
//     //GetVelocity is in rpm and you need to convert to meters per sec(no false might have been updated)
//     //It actually returns volts per sec actually nvm it does return rpm documentation is a lie I think
//     wheelsSpeeds.left =  m_leftLeadMotor.GetEncoder().GetVelocity() / AutoConst::kgear_ratio *AutoConst::kwheel_diameter_meters *M_PI / 60;
//     wheelsSpeeds.right =  m_rightLeadMotor.GetEncoder().GetVelocity() / AutoConst::kgear_ratio *AutoConst::kwheel_diameter_meters *M_PI / 60;
//     return wheelsSpeeds;

//     // m_leftLeadMotor.GetEncoder().GetVelocity() *(AutoConst::kwheel_diameter_meters* M_PI) / (AutoConst::kgear_ratio*60),
//     // m_rightLeadMotor.GetEncoder().GetVelocity() *(AutoConst::kwheel_diameter_meters *M_PI) / (AutoConst::kgear_ratio*60)

// }

void Auto::Start(){
    std::cout<<"uhh in start"<<std::endl;

    //GenerateTrajectory();
    //Runs the Auto::Reset which well resets motor direction, encoders,and gyro
    Auto::Reset();
    std::cout<<"reset"<<std::endl;
    //Starts the timer
    m_timer->Start();
    std::cout<<"start"<<std::endl;

    //resets the Odometry to the initial positions of the trajectory
    ResetOdometry(trajectory.InitialPose());
    std::cout<<"resetod"<<std::endl;

}

bool Auto::RunRamsete(){
    if (m_timer->Get()< trajectory.TotalTime()){
        // Get the desired pose at the current time from the trajectory.
        auto desiredPose = trajectory.Sample(m_timer->Get());

        // Get the reference chassis speeds from the Ramsete Controller with the current position obtained by UpdateOdometry() and the desiredPose.
        auto refChassisSpeeds = ramsetecontroller.Calculate(UpdateOdometry(), desiredPose);

        //runs drive with given linear speed and rotational speed
        Drive(refChassisSpeeds.vx, refChassisSpeeds.omega);

    }else {
      //stops motors and timer
      Drive(0_mps, 0_rad_per_s);
      m_timer->Stop();
      m_timer->Reset();
      return true;
    }
    return false;

}