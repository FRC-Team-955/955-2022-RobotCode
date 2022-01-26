#ifndef BALL_MANAGER
#define BALL_MANAGER
#include <ctre/phoenix.h>
#include <frc/Solenoid.h>
#include <frc/Joystick.h>
#include <iost#ifndef BALLMANAGER
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

class BallManager {
public:
  BallManager() {}
  std::string GetHopperState(int position);
  void Shoot();
  bool MoveIndex(int start, int end);
  


private:
  std::string position[2];//position[0] = color of position 1 position[1] = color of position 2
  position[0] = "NULL";
  position[1] = "NULL";
  std::string inbetween;
};
#endifream>
#include <string>
#include "hopper.h"
#include "breakbeam.h"
#include "settings.h"
#include "colorsensor.h"
using namespace frc;

class BallManager{
    public:
        std::string GetHopperState (int position);
        void ShootBall();
        bool MoveIndex(0, 1);
    private:
        std::string Ball1[2]; // Ball1[0] == "COlor" Ball1[1] = index
        std::string Ball2[2];
        Hopper hopper_0;
        Hopper hopper_1;
        Hopper hopper_NULL;

};

#endif