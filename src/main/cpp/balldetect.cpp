#include "balldetect.h"


int BallDetect::BallDetectorX(){
photonlib::PhotonPipelineResult result = camera.GetLatestResult();



if (result.HasTargets()) {
    return result.GetBestTarget().GetYaw();
} else {

return false;

}

	

    
}

int BallDetect::BallDetectorY(){
photonlib::PhotonPipelineResult result = camera.GetLatestResult();




	
if (result.HasTargets()) {
    return result.GetBestTarget().GetPitch();
} else{
	
        return false;
    }    
}

