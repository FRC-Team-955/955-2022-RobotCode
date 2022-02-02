#include <frc/AnalogInput.h>
#include <ultrasonic.h> 
#include <iostream> 
using namespace frc; 

double UltraSonic::SonicDistance(std::string passin) {
double rawValue = ultrasonic.GetValue();

if (passin == "in")
{
return rawValue*0.0492;
}

if (passin == "cm")
{
return rawValue*0.125;
}

}
