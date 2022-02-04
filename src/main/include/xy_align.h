#ifndef XYALIGH
#define XYALIGH

#include <frc/Joystick.h>
#include <iostream>
#include <AHRS.h>
#include <ctre/Phoenix.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h" 
#include "drivebase.h"

using namespace frc;

class XYalign{
    public:
        XYalign(DriveBase *drivebase):drivebase(drivebase) {};
            void test();
            BallManager ball_manage;

    private:
        DriveBase *drivebase; 
        frc::Joystick joystick{0};
        
};
#endif