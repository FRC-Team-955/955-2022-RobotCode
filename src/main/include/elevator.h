#ifndef ELEVATOR
#define ELEVATOR
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <frc/DigitalInput.h>
using namespace frc;
#include "settings.h"


class Elevator {
public:
  Elevator() {
    elevator_motor.SetNeutralMode(NeutralMode::Brake);
    elevator_motor.TalonSRX::ConfigSupplyCurrentLimit(40);
    elevator_motor.TalonSRX::EnableSupplyCurrentLimit(true);
  }
  void ElevatorMove(int joystick_position);
  void LockElevator();
  void UnlockElevator();


private:
  bool bot_switch = 0;
  DigitalInput limit_switch_top{SensorConst::limit_switch_top_port};
  DigitalInput limit_switch_bottom{SensorConst::limit_switch_bottom_port};
  TalonFX elevator_motor{MechanismConst::kelevator_motor_port};
  Solenoid solenoid0{PneumaticsModuleType::CTREPCM , 0};
};
#endif
