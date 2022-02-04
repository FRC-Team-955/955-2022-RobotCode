#ifndef MOTORTESTER2
#define MOTORTESTER2
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/shuffleboard/ShuffleboardRoot.h>
#include <iostream>
using namespace frc;

class MotorTester {
    public:
        void getPortNumber();
        void getPower();
        void displayVelocity();
        void displayPosition();
    private:
        int motor_port;
};

#endif