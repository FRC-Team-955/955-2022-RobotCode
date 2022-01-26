#ifndef BREAKBEAM
#define BREAKBEAM

#include <frc/DigitalInput.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "settings.h"

class BeamBreak {
public:
  BeamBreak() {
    digitalinput = new frc::DigitalInput(SensorConst::kbreak_beam_port);
  }
  bool BeamBroken();

private:
  frc::DigitalInput *digitalinput;
  bool broken;
};
#endif
