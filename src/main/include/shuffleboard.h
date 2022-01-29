#ifndef SHUFFLEBOARD
#define SHUFFLEBOARD
#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "settings.h"

using namespace frc;
using namespace std; 

class ShuffleBoard {
ShuffleBoard(){
    ShuffleboardTab& tab_auto = Shuffleboard::GetTab("Auto");
  ShuffleboardTab& tab_telop = Shuffleboard::GetTab("Telop");
  ShuffleboardTab& tab_endgame = Shuffleboard::GetTab("End Game");
  // frc::Shuffleboard::GetTab("Auto");
};
void UpdateShuffleBoard();
public:

private: 

};
#endif