#ifndef BALL_MANAGER
#define BALL_MANAGER
#include <ctre/phoenix.h>
#include <frc/Solenoid.h>
#include <frc/Joystick.h>
#include "hopper.h"
#include "breakbeam.h"
#include "settings.h"
using namespace frc;

class BallManager{
    public:
        int GetBallColor(); // put 0 or 1 and return color
        void ShootBalls(); // input voloceity for the shooter, push the ball into the shooter
        float set_velocity;

    private:
        BeamBreak hopper_break_beam;
        Hopper hopper_0;
        Hopper hopper_1;
        Hopper hopper_NULL = NULL;
};

#endif