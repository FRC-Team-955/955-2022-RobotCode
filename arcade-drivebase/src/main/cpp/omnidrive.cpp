#include "omnidrive.h"
#include "settings.h"
using namespace frc;
//please work
void Omnidrive::Drive(){
	right = (joy->GetRawAxis(4) + joy->GetRawAxis(1));
	left = (-joy->GetRawAxis(4) + joy->GetRawAxis(1));

	right = right * right * right;
	left = left * left * left;
	left = std::min(1.0, left);
	right = std::min(1.0, right);
	left = std::max(-1.0, left);
	right = std::max(-1.0, right);
	rightLeadMotor->Set(ControlMode::PercentOutput, -1 * left);
	leftLeadMotor->Set(ControlMode::PercentOutput, right * 1);
    rightFollowerMotor->Set(ControlMode::PercentOutput, -1 * left);
	leftFollowerMotor->Set(ControlMode::PercentOutput, right * 1);
}
