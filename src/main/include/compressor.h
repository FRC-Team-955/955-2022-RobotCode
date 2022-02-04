#ifndef COMPRESSOR
#define COMPRESSOR
#include "settings.h"
#include <frc/Compressor.h>
#include <frc/Solenoid.h>
#include <string>

using namespace frc;

class RobotCompressor {
public:
  void TurnOnCompressor();  // turns on compressor
  void TurnOffCompressor(); // turns off compressor
  bool DetectPressure();    // returns pressure
private:
  Compressor compressor{PneumaticsModuleType::CTREPCM};
};

#endif