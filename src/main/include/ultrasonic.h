#ifndef ULTRASONIC
#define ULTRASONIC

#include <string>
#include <frc/AnalogInput.h>
#include "settings.h"

using namespace frc;

class UltraSonic {
public:
  double SonicDistance(std::string passin);
  AnalogInput ultrasonic{SensorConst::kultrasonic_port};

private:
    double raw_value = 100;
};
#endif