#pragma once

namespace Joy0Const {
constexpr int kquick_turn_button = 1;
constexpr int kdrive_speed_axis = 1;
constexpr int kdrive_curvature_axis = 1;
} // namespace Joy0Const

namespace Joy1Const {}

namespace SensorConst {
constexpr int kbreak_beam_port = 0;
}

namespace DriveConst {
constexpr int kleft_lead_neo_number = 3;
constexpr int kright_lead_neo_number = 4;
constexpr int kleft_follow_neo_number = 2;
constexpr int kright_follow_neo_number = 5;
} // namespace DriveConst

namespace MechanismConst {double kP = 1, kI = 1, kD = 1, kIz = 1, kFF = 1, kMaxOutput = 1, kMinOutput = 1;}
constexpr int shootertalon_follow = 1; 
namespace AutoConst {}
