#ifndef ULTRASONIC
#define ULTRASONIC

#include "settings.h"
#include <frc/AnalogInput.h>
#include <string>


using namespace frc;

class UltraSonic {
public:
  double SonicDistance(std::string passin);

private:
  AnalogInput ultrasonic{SensorConst::kultrasonic_port};
  double raw_value = 100;
};
#endif