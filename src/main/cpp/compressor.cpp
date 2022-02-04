#include "compressor.h"

void RobotCompressor::TurnOnCompressor() {
  compressor.EnableDigital(); // turns on compressor
}

void RobotCompressor::TurnOffCompressor() {
  compressor.Disable(); // turns off compressor
}

bool RobotCompressor::DetectPressure() {
  if (compressor.GetPressure() <
      (units::pounds_per_square_inch_t)
          MechanismConst::kcompressor_warning_pressure) {
    return true;
  } else {
    return false;
  }
}