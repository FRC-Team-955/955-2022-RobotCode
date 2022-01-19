#ifndef XYALIGH
#define XYALIGH

#include <frc/Joystick.h>
#include <iostream>
#include <AHRS.h>
#include <ctre/Phoenix.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h" 

using namespace frc;

class XYalign{
    public:
        XYalign(TalonSRX *talon_drive_right_enc,
            TalonSRX *talon_drive_right_noenc,
            TalonSRX *talon_drive_left_enc,
            TalonSRX *talon_drive_left_noenc, 
            frc::Joystick * joy0,
            AHRS*ahrs): 
            talon_drive_right_enc(talon_drive_right_enc),
            talon_drive_right_noenc(talon_drive_right_noenc),
            talon_drive_left_enc(talon_drive_left_enc),
            talon_drive_left_noenc(talon_drive_left_noenc), 
            joy0(joy0),
            ahrs(ahrs){};
            double left_drive;
            double right_drive;
            bool Align;
            void test();
    private:
        TalonSRX *talon_drive_right_enc;
        TalonSRX *talon_drive_right_noenc;
        TalonSRX *talon_drive_left_enc;
        TalonSRX *talon_drive_left_noenc;
        Joystick *joy0;
        AHRS *ahrs; 
        double degree;
        double vertical_offset;
        double horizontal_offset;
        double target_offset_angle_horizontal;
};
#endif