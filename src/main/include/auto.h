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
        m_leftLeadMotor.GetEncoder().SetPosition(0);
        m_rightLeadMotor.GetEncoder().SetPosition(0);
        m_leftLeadMotor.SetSmartCurrentLimit(40);
        m_rightLeadMotor.SetSmartCurrentLimit(40);
        gyro.Reset();
        config.SetKinematics(kinematics);
        m_timer = new frc::Timer();
    };
    //Resets follow, inversion, encoders, and gyro
    void Reset();

    //Resets the Odometry to the inputed position
    void ResetOdometry(const frc::Pose2d& pose);

    //Returns the Rotation2d(direction) of the robot
    frc::Rotation2d GetHeading();

    //Returns the position of the robot
    frc::Pose2d UpdateOdometry();

    //Coverts Linear and Rotational speed into left and right rotation speed. With values instantly runs SetSpeeds 
    void Drive(units::meters_per_second_t xSpeed,units::radians_per_second_t rot);
    //Run the wheels at a target volocity
    void SetSpeeds(const frc::DifferentialDriveWheelSpeeds& speeds);

    //Generates a Trajectory of a line
    void GenerateTrajectory();
    //Sets the trajectory to the inputed Trajectory
    void SetTrajectory(frc::Trajectory trajectory_input);

    //frc::DifferentialDriveWheelSpeeds GetSpeeds();
    // void SetOutput(double leftVolts,double rightVolts);

    //Trajectory Follower
    void Start();
    bool RunRamsete();
private:
    // double leftVolts;
    // double rightVolts;

    //Creates all the SparkMax
    CANSparkMax m_leftLeadMotor{DriveConst::kright_lead_neo_number,CANSparkMax::MotorType::kBrushless}; 
    CANSparkMax m_rightLeadMotor{DriveConst::kright_lead_neo_number,CANSparkMax::MotorType::kBrushless};
    CANSparkMax m_leftFollowMotor{DriveConst::kleft_follow_neo_number,CANSparkMax::MotorType::kBrushless};
    CANSparkMax m_rightFollowMotor{DriveConst::kright_follow_neo_number,CANSparkMax::MotorType::kBrushless};

    //Creates the Navx
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
    frc::RamseteController ramsetecontroller;

    frc::Timer *m_timer;
};
#endif
