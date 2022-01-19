#include "xy_align.h"

using namespace frc;

void XYalign::test(){
  std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
  degree = ahrs->GetAngle();
  double vertical_offset = table->GetNumber("ty", 0.0);
  double drive_adjustment = vertical_offset;
  int xp = joy0->GetRawAxis(4);
  int yp = joy0->GetRawAxis(1);
  bool target_set = false;
  horizontal_offset = table->GetNumber("tx", 0.0);
  std::cout << "Math1: " << horizontal_offset - degree << std::endl;
  talon_drive_right_enc->Set(ControlMode::PercentOutput, .3 * (yp+xp));
  talon_drive_left_enc->Set(ControlMode::PercentOutput, .3 * (xp-yp));
  if (table -> GetNumber("tv", 0.0)){
    if(target_set == false){
       target_offset_angle_horizontal = table->GetNumber("tx",0.0);
       target_set = true;
       ahrs->ZeroYaw();
   }
   if (horizontal_offset - degree < 0.1 and horizontal_offset - degree > -0.1) {
    Align = true;
    std::cout << "Aligned" << std::endl;
    //talon_drive_right_enc->Set(ControlMode::PercentOutput, .3 * (yp+xp));
    //talon_drive_left_enc->Set(ControlMode::PercentOutput, .3 * (xp-yp));
  }
  else if (horizontal_offset -degree > 0.20 /*and Align == false*/) {
    //left_drive=  HorizontalOffset/ 45;
    std::cout << "Going left" << std::endl;
    left_drive = (horizontal_offset -degree) * -0.05 ;
    right_drive = 0;
  }

  else if (horizontal_offset - degree < -.20 /*and Align == false*/){
    //right_drive = HorizontalOffset/ 45;
    std::cout << "Going right" << std::endl;
    right_drive = (horizontal_offset -degree) * -0.05;
    left_drive = 0;
  } 
  else {
      right_drive = 0;
      left_drive = 0;
  }
  }
  if (joy0->GetRawButton(2)==1){
    Align = false;
  }
  if (joy0->GetRawButton(1)==1){
    target_set = false;
  }
  std::cout<<horizontal_offset<<std::endl; 
  std::cout<< "Right: "<<right_drive<<std::endl;
  std::cout<< "Left: "<<left_drive<<std::endl;
  if(joy0->GetRawButton(3)==1){
    talon_drive_right_enc->Set(ControlMode::PercentOutput, (.15 * - right_drive));
    talon_drive_left_enc->Set(ControlMode::PercentOutput, (-.15 * - left_drive));
  }
  std::cout<<drive_adjustment<<std::endl;
  std::cout<<"Target: "<<target_set<<std::endl;
}