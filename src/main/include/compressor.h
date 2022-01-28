#ifndef COMPRESSOR
#define COMPRESSOR
#include <frc/Solenoid.h>
#include <frc/Compressor.h>
#include <string>
#include "settings.h"
using namespace frc;

class Compressor1 {
    public:
        void TurnOnComp(); // turns on compressor
        void TurnOffComp(); // turns off compressor
        bool DetectPressure(); // returns pressure
    private:
    Compressor Compressor_1{PneumaticsModuleType::CTREPCM};
};

#endif