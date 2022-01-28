#include "elevator.h"
#include "shuffleboard.h" 
#include <frc/shuffleboard/Shuffleboard.h>
using namespace frc;

void Elevator::ElevatorMove(int joystick_position) {
  if (solenoid0.Get() == 1) {
    elevator_motor.SetNeutralMode(NeutralMode::Brake);
    elevator_motor.Set(ControlMode::PercentOutput, 0);
  }
  if (limit_switch_top.Get() == 1 && joystick_position > 0) {
    elevator_motor.SetNeutralMode(NeutralMode::Brake);
    elevator_motor.Set(ControlMode::PercentOutput, 0);
  } else if (limit_switch_top.Get() == 1 && joystick_position < 0) {
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position);
  }
  if (limit_switch_bottom.Get() == 1 && joystick_position < 0) {
    elevator_motor.SetNeutralMode(NeutralMode::Brake);
    elevator_motor.Set(ControlMode::PercentOutput, 0);
  } else if (limit_switch_bottom.Get() == 1 && joystick_position > 0) {
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position);
  }
  if (elevator_motor.GetSelectedSensorPosition() > 4000) {
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position * 0.5);
  } else if (elevator_motor.GetSelectedSensorPosition() < 1000) {
    elevator_motor.Set(ControlMode::PercentOutput, joystick_position * 0.5);
  }
}

void Elevator::LockElevator() {
  solenoid0.Set(1);
  elevator_motor.SetNeutralMode(NeutralMode::Brake);
  elevator_motor.Set(ControlMode::PercentOutput, 0);
}

void Elevator::UnlockElevator() { solenoid0.Set(0); }

void Elevator::ElevatorAmp(int amp) {
  amp = elevator_motor.GetOutputCurrent();
}

void Elevator::ElevatorPosition(int position) {
  position = elevator_motor.GetSelectedSensorPosition(0);
}

void Elevator::ElevatorPneumaticState(int pneumatic) {
  pneumatic = solenoid0.Get(); 
  string f; 
  f = "Hi";
  frc::Shuffleboard::GetTab("Auto");
  Shuffleboard::GetTab(f);
}



