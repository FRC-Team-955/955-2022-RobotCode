#ifndef BALLDETECT
#define BALLDETECT


#include "photonlib/PhotonUtils.h"
#include "photonlib/PhotonCamera.h"
#include <iostream>

class BallDetect{
		public:
 		BallDetect(){
            
             
         }
			double BallDetectorY(photonlib::PhotonPipelineResult result);
			double BallDetectorX(photonlib::PhotonPipelineResult result);

			

	    private:
          bool BallDetected;
		 


};
#endif
