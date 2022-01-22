#ifndef AUTO
#define AUTO

#include "rev/CANSparkMax.h"

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>

#include <frc/geometry/Pose2d.h>

#include "AHRS.h"

#include "settings.h"

using namespace rev;


class Auto {
public:
  Auto() {
    m_leftFollowMotor.Follow(m_leftLeadMotor);
    m_rightFollowMotor.Follow(m_rightLeadMotor);
    
    m_leftLeadMotor.SetInverted(false);
    m_rightLeadMotor.SetInverted(true);
    
  };

  frc::Rotation2d GetHeading();
  frc::DifferentialDriveWheelSpeeds GetSpeeds();

private:
    CANSparkMax m_leftLeadMotor{DriveConst::kleft_lead_neo_number,CANSparkMax::MotorType::kBrushless};
    CANSparkMax m_rightLeadMotor{DriveConst::kright_lead_neo_number,CANSparkMax::MotorType::kBrushless};
    CANSparkMax m_leftFollowMotor{DriveConst::kleft_follow_neo_number,CANSparkMax::MotorType::kBrushless};
    CANSparkMax m_rightFollowMotor{DriveConst::kright_follow_neo_number,CANSparkMax::MotorType::kBrushless};

    AHRS gyro{frc::SPI::Port::kMXP};

    frc::Pose2d pose;

    frc::DifferentialDriveKinematics kinematics{AutoConst::ktrack_width_meters};
    frc::DifferentialDriveOdometry odometry{GetHeading(), pose};
    



};
#endif
