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
        // pass vel into thais funciton, then get vel and if vel is in the range, then shoot one ball, then put the other ball into second position and wait for velocity to rise again.

    private:
        TalonSRX hopper_motor {1};
        TalonSRX shooter_motor {1};
        BeamBreak hopper_break_beam;
};

#endif