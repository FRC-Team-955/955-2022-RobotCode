#ifndef PNEUMATICS
#define PNEUMATICS
#include <frc/Solenoid.h>
#include <frc/Compressor.h>
using namespace frc;

class Pneumatics {
    public:
        void OnOff();
    private:
    Compressor Pneumatics{PneumaticsModuleType::CTREPCM};
};

#endif