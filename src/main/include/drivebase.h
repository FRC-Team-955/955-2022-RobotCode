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
  };
  void Drive();


 	    DriveBase() {};
        void Drive();
        void DriveTank(float leftWheelInput, float rightWheelInput);
	private:
	
		rev::CANSparkMax m_leftLeadMotor{3, rev::CANSparkMax::MotorType::kBrushless};
                rev::CANSparkMax m_rightLeadMotor{4, rev::CANSparkMax::MotorType::kBrushless};
                rev::CANSparkMax m_leftFollowMotor{2, rev::CANSparkMax::MotorType::kBrushless};
                rev::CANSparkMax m_rightFollowMotor{5, rev::CANSparkMax::MotorType::kBrushless};


  frc::DifferentialDrive m_robotDrive{m_leftLeadMotor, m_rightLeadMotor};

  frc::Joystick joystick{0};
};
#endif
