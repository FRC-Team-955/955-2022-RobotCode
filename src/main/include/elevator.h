#ifndef ELEVATOR
#define ELEVATOR
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <frc/DigitalInput.h>
using namespace frc;
#include "settings.h"
#include "rev/CANSparkMax.h"
using namespace rev;

class Elevator {
public:
  Elevator() {}
  void ElevatorMove(int joystick_position);
  void LockElevator();
  void UnlockElevator();


private:
  DigitalInput limit_switch_top{SensorConst::limit_switch_top_port};
  DigitalInput limit_switch_bottom{SensorConst::limit_switch_bottom_port};
  CANSparkMax elevator_motor{MechanismConst::kelevator_motor_port, CANSparkMax::MotorType::kBrushless};
  Solenoid solenoid0{PneumaticsModuleType::CTREPCM , 0};
};
#endif
