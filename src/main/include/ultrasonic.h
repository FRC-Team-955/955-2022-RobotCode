#ifndef ULTRASONIC
#define ULTRASONIC
#include <frc/AnalogInput.h>
#include "settings.h"
#include <string> 
using namespace frc; 
using namespace SensorConst;


class UltraSonic {
public: 
double SonicDistance(std::string passin);
AnalogInput ultrasonic{analogpin_for_hypersonic_sensor};
private:

}; 
#endif