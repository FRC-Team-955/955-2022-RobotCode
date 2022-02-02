#include <frc/AnalogInput.h>
#include <ultrasonic.h> 
using namespace frc; 

void UltraSonic::SonicDistance() {
double rawValue = ultrasonic.GetValue();
double currentDistanceInches = rawValue*0.0492;
}
