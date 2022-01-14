#include "breakbeam.h"

    

bool BeamBreak::BeamBroken(){
	broken = digitalinput->Get();
	
return broken;
    
}
