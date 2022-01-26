#include "xy_align.h"

using namespace frc;

void XYalign::test(){

  //std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("photonvision");
  auto table = nt::NetworkTableInstance::GetDefault().GetTable("photonvision");
 
  double vertical_offset = table->GetNumber("targetPixelsX", 0.0);
  //double drive_adjustment = vertical_offset;
  //bool target_set = false;
  //horizontal_offset = table->GetNumber("targetPixelsY", 0.0);
  std::cout << "Vertical Offset: " << vertical_offset << std::endl;

}