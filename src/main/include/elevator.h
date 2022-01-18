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
    
  }
  int ElevatorMove(int joystick_position);
  void LockElevator();
  void UnlockElevator();


private:
  DigitalInput limit_switch_top{1};
  DigitalInput limit_switch_bottom{2};
  TalonFX hopper_motor{7};
  Solenoid solenoid0{PneumaticsModuleType::CTREPCM , 0};
  
};
#endif
