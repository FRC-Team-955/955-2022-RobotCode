#ifndef ULTRASONIC
#define ULTRASONIC
#include <frc/AnalogInput.h>
using namespace frc; 


class UltraSonic {
public: 
void SonicDistance();
AnalogInput ultrasonic{0};
private:

}; 
#endif