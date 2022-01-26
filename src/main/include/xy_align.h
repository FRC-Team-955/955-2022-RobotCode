#ifndef XYALIGH
#define XYALIGH

#include <frc/Joystick.h>
#include <iostream>

#include "frc/smartdashboard/Smartdashboard.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
using namespace frc;

class XYalign{
    public:
        XYalign();
            // double left_drive;
            // double right_drive;
            // bool Align;
        void test();
    private:
        
        //double degree;
        double vertical_offset;
        // double horizontal_offset;
        // double target_offset_angle_horizontal;
};
#endif