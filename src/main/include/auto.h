#ifndef AUTO
#define AUTO


#include "rev/CANSparkMax.h"

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/controller/PIDController.h>

#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <frc/trajectory/TrajectoryGenerator.h>

#include <frc2/command/RamseteCommand.h>
#include <frc/controller/RamseteController.h>

#include <frc/geometry/Pose2d.h>

#include <frc/Timer.h>

#include "AHRS.h"

#include <math.h>

#include "settings.h"

using namespace rev;


class Auto {
public:
    Auto() {
        m_leftFollowMotor.Follow(m_leftLeadMotor);
        m_rightFollowMotor.Follow(m_rightLeadMotor);

        m_leftLeadMotor.SetInverted(false);
        m_rightLeadMotor.SetInverted(true);

        config.SetKinematics(kinematics);
    };

    frc::Rotation2d GetHeading();
    frc::Pose2d UpdateOdometry();
    

    void Drive(units::meters_per_second_t xSpeed,units::radians_per_second_t rot);

    void SetSpeeds(const frc::DifferentialDriveWheelSpeeds& speeds);


    void GenerateTrajectory();

    //frc::DifferentialDriveWheelSpeeds GetSpeeds();
    // void SetOutput(double leftVolts,double rightVolts);


    //from Trajectory Follower
    bool RunRamsete();
    

private:
    // double leftVolts;
    // double rightVolts;

    CANSparkMax m_leftLeadMotor{DriveConst::kleft_lead_neo_number,CANSparkMax::MotorType::kBrushless};
    CANSparkMax m_rightLeadMotor{DriveConst::kright_lead_neo_number,CANSparkMax::MotorType::kBrushless};
    CANSparkMax m_leftFollowMotor{DriveConst::kleft_follow_neo_number,CANSparkMax::MotorType::kBrushless};
    CANSparkMax m_rightFollowMotor{DriveConst::kright_follow_neo_number,CANSparkMax::MotorType::kBrushless};

    AHRS gyro{frc::SPI::Port::kMXP};

    frc::Pose2d pose;

    frc::DifferentialDriveKinematics kinematics{AutoConst::ktrack_width_meters};
    frc::DifferentialDriveOdometry odometry{GetHeading(), pose};
    
    frc::DifferentialDriveWheelSpeeds wheelsSpeeds{}; 

    //Get actual values later from sysid 2022
    frc::SimpleMotorFeedforward<units::meters> feedforward{AutoConst::kS,AutoConst::kV, AutoConst::kA};
    frc::PIDController leftPIDController{AutoConst::kP,AutoConst::kI,AutoConst::kD};
    frc::PIDController rightPIDController{AutoConst::kP,AutoConst::kI,AutoConst::kD};


    frc::TrajectoryConfig config{AutoConst::kmax_velocity,AutoConst::kmax_acceleration};
    frc::TrajectoryGenerator trajectoryGenerator;
    frc::Trajectory trajectory;

    //has default values of 2.0 and 0.7
    frc::RamseteController controller;
    frc::Timer m_timer;


};
#endif
