#ifndef DRIVEBASE
#define DRIVEBASE

#include "rev/CANSparkMax.h"
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>

#include "settings.h"

using namespace rev;

class DriveBase {
public:
  DriveBase() {
    m_rightFollowMotor.Follow(m_rightLeadMotor);
    m_leftFollowMotor.Follow(m_leftLeadMotor);
    m_leftLeadMotor.SetInverted(DriveConst::kleft_lead_is_inverted);
    m_rightLeadMotor.SetInverted(DriveConst::kright_lead_is_inverted);
  };
  void Drive();

private:
  CANSparkMax m_leftLeadMotor{DriveConst::kleft_lead_neo_number,
                              CANSparkMax::MotorType::kBrushless};
  CANSparkMax m_rightLeadMotor{DriveConst::kright_lead_neo_number,
                               CANSparkMax::MotorType::kBrushless};
  CANSparkMax m_leftFollowMotor{DriveConst::kleft_follow_neo_number,
                                CANSparkMax::MotorType::kBrushless};
  CANSparkMax m_rightFollowMotor{DriveConst::kright_follow_neo_number,
                                 CANSparkMax::MotorType::kBrushless};

  frc::DifferentialDrive m_robotDrive{m_leftLeadMotor, m_rightLeadMotor};

  frc::Joystick joystick{0};

  bool ReverseDrive = false;
};
#endif
