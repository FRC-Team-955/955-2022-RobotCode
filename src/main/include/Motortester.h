#ifndef MOTORTESTER
#define MOTORTESTER
#include <iostream>
#include "frc/Joystick.h"
#include "ctre/Phoenix.h"
#include "frc/Timer.h"
using namespace frc;

class Motor {
    public:
    void motor_test();

    private:
    int stage = 1;
    Timer time{};
    Joystick joy1{0};
    TalonSRX motor1{1};
    TalonSRX motor2{2};
    TalonSRX motor3{3};
    TalonSRX motor4{4};
    TalonSRX motor5{5};
    TalonSRX motor6{6};
    TalonSRX motor7{7};
    TalonSRX motor8{8};
};

#endif