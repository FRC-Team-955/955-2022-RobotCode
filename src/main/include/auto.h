#ifndef AUTO
#define AUTO

#include "rev/CANSparkMax.h"

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/controller/PIDController.h>

#include <frc/trajectory/TrajectoryConfig.h>

#include <frc2/command/RamseteCommand.h>

#include <frc/geometry/Pose2d.h>

#include "AHRS.h"

#include <math.h>

#include <units/energy.h>

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
    frc::DifferentialDriveWheelSpeeds GetSpeeds();
    void UpdateOdometry();
    

private:
    CANSparkMax m_leftLeadMotor{DriveConst::kleft_lead_neo_number,CANSparkMax::MotorType::kBrushless};
    CANSparkMax m_rightLeadMotor{DriveConst::kright_lead_neo_number,CANSparkMax::MotorType::kBrushless};
    CANSparkMax m_leftFollowMotor{DriveConst::kleft_follow_neo_number,CANSparkMax::MotorType::kBrushless};
    CANSparkMax m_rightFollowMotor{DriveConst::kright_follow_neo_number,CANSparkMax::MotorType::kBrushless};

    AHRS gyro{frc::SPI::Port::kMXP};

    frc::Pose2d pose;

    frc::DifferentialDriveKinematics kinematics{AutoConst::ktrack_width_meters};
    frc::DifferentialDriveOdometry odometry{GetHeading(), pose};
    

    //Get actual values later from sysid 2022
    frc::SimpleMotorFeedforward<units::meters> feedforward{AutoConst::kS,AutoConst::kV};

    //
    frc::PIDController leftPIDController{9.95,0,0};
    frc::PIDController rightPIDController{9.95,0,0};

    frc::TrajectoryConfig config{AutoConst::kmax_velocity,AutoConst::kmax_acceleration};

    frc::RamseteController command{}


};
#endif
