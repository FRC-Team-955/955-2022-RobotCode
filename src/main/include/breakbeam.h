#ifndef BREAKBEAM
#define BREAKBEAM

#include <frc/DigitalInput.h>



int pin = 0;

class BeamBreak {
		public:
 		BeamBreak(){
            digitalinput = new frc::DigitalInput(pin);
             
         }
			bool BeamBroken();
			
			

	    private:
		    frc::DigitalInput * digitalinput;
            bool broken;


};
#endif
