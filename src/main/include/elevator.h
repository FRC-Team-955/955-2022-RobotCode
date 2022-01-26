#ifndef ELEVATOR
#define ELEVATOR
#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <frc/shuffleboard/Shuffleboard.h>

using namespace frc;
#include "settings.h"

class Elevator {
public:
  Elevator() {}
  void ElevatorMove(int joystick_position);
  void LockElevator();
  void UnlockElevator();
  void ElevatorAmp(int amp); 
  void ElevatorPosition(int position);
  void ElevatorSpeedLimit(int speed);
  void ElevatorPneumaticState(int pneumatic);
private:
  DigitalInput limit_switch_top{SensorConst::limit_switch_top_port};
  DigitalInput limit_switch_bottom{SensorConst::limit_switch_bottom_port};
  TalonFX elevator_motor{MechanismConst::kelevator_motor_port};
  Solenoid solenoid0{PneumaticsModuleType::CTREPCM, MechanismConst::kelevator_pnumatic_port};
};
#endif
