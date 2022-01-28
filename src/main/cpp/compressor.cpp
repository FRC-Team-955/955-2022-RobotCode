#include "compressor.h"

void Compressor1::TurnOnComp(){
    Compressor_1.EnableDigital(); // turns on compressor
}

void Compressor1::TurnOffComp(){
    Compressor_1.Disable(); // turns off compressor
}

bool Compressor1::DetectPressure(){
    if (Compressor_1.GetPressure() < (units::pounds_per_square_inch_t)MechanismConst::kcompressor_maximum_pressure){
        return true;
    } else {
        return false;
    }
}