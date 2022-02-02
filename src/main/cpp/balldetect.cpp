#include "balldetect.h"


double BallDetect::BallDetectorX(photonlib::PhotonPipelineResult result){

if (result.HasTargets()) {
  
    return result.GetBestTarget().GetYaw();
 
} else {

return 0;

}

	

    
}

double BallDetect::BallDetectorY(photonlib::PhotonPipelineResult result){
	
if (result.HasTargets()) {
    return result.GetBestTarget().GetPitch();
} else{
	
        return 0;
    }    
}

