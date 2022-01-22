#ifndef BALL_MANAGER
#define BALL_MANAGER
#include <ctre/phoenix.h>
#include <frc/Solenoid.h>
#include <frc/Joystick.h>
#include <iostream>
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