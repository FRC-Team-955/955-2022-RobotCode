#ifndef BALLMANAGER
#define BALLMANAGER
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <frc/DigitalInput.h>
using namespace frc;
#include "settings.h"
#include <iostream>
#include "hopper.h"
#include "breakbeam.h"
#include "colorsensor.h"
#include "hopper.h"
#include "shooter.h"
#include "ultrasonic.h"

class BallManager {
public:
  BallManager(){};
  std::string GetHopperState(int position);
  bool Rev();
  void MoveIndex();
  void CheckHopperState();
  bool IsEmpty();
  void LoadHopper();
  void Reject();
  void Shoot();
  int motor_velocity = 0;
  int target_velocity = 0;
  int range = 0;
  


private:
  std::string position[2] = {"NULL", "NULL"};//position[0] = color of position 1 position[1] = color of position 2
  std::string inbetween = "NULL";
  std::string team_color = "Red";

  ColorSensor color_sensor;
  BeamBreak break_beam;
  Hopper hopper;
  Shooter shooter;

};
#endif