#ifndef BALLDETECT
#define BALLDETECT

#include <photonlib/PhotonUtils.h>
#include <photonlib/PhotonCamera.h>
#include <iostream>

class BallDetect{
		public:
 		BallDetect(){
            
             
         }
			int BallDetectorY();
			int BallDetectorX();

			

	    private:
          bool BallDetected;
		  photonlib::PhotonCamera camera{"BallDetect"};


};
#endif
