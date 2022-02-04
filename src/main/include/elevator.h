#ifndef ELEVATOR
#define ELEVATOR
#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>

using namespace frc;
#include "settings.h"

class Elevator {
public:
  Elevator() {
    elevator_motor.SetNeutralMode(NeutralMode::Brake);
    elevator_motor.TalonFX::ConfigSupplyCurrentLimit(
        SupplyCurrentLimitConfiguration(true, 40, 40, 0.1));
    // line above sets current limit. SupplyCurrentLimitConfiguration goes as
    // follow: CupplyCurrentLimitConfiguration(enable, current limit,
    // triggerThresholdCurrent, triggerThresholdTime)
  }
  void ElevatorMove(int joystick_position);
  void LockElevator();
  void UnlockElevator();
  bool OffGround();

private:
  bool set_up_done = false;
  DigitalInput limit_switch_top{SensorConst::limit_switch_top_port};
  DigitalInput limit_switch_bottom{SensorConst::limit_switch_bottom_port};
  TalonFX elevator_motor{MechanismConst::kelevator_motor_port};
  Solenoid solenoid0{PneumaticsModuleType::CTREPCM,
                     MechanismConst::kelevator_pnumatic_port};
};
#endif