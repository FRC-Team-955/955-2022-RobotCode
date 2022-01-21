#pragma once

namespace Joy0Const {
constexpr int kquick_turn_button = 1;
constexpr int kdrive_speed_axis = 1;
constexpr int kdrive_curvature_axis = 1;
constexpr int kreverse_drive = 4;
} // namespace Joy0Const

namespace Joy1Const {}

namespace SensorConst {
constexpr int kbreak_beam_port = 0;

//value at which color sensor proximity will return there is a ball 0(far away) - 2047(close as possible)
constexpr int kvalue_for_ball = 2000;
}

namespace DriveConst {
constexpr int kleft_lead_neo_number = 3;
constexpr int kright_lead_neo_number = 4;
constexpr int kleft_follow_neo_number = 2;
constexpr int kright_follow_neo_number = 5;
} // namespace DriveConst

namespace MechanismConst {}

namespace AutoConst {}
