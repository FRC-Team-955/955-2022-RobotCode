#pragma once

namespace Joy0Const {
constexpr int kquick_turn_button = 1;
constexpr int kdrive_speed_axis = 1;
constexpr int kdrive_curvature_axis = 5;
constexpr int kreverse_drive = 4;
} // namespace Joy0Const

namespace Joy1Const {
constexpr int kshooter_axis = 0;
constexpr int khopper_top_axis = 4;    // I think these are the triggers?
constexpr int khopper_bottom_axis = 5; // I think these are the triggers?
constexpr int kelevator_axis = 3;      // right stick up and down?
constexpr int kelevator_lock_button = 1;
} // namespace Joy1Const

namespace SensorConst {
constexpr int kbreak_beam_port = 0;
constexpr int limit_switch_top_port = 1;
constexpr int limit_switch_bottom_port = 2;
// value at which color sensor proximity will return there is a ball 0(far away)
// - 2047(close as possible)
constexpr int kvalue_for_ball = 2000;
} // namespace SensorConst

namespace DriveConst {
constexpr int kleft_lead_neo_number = 3;
constexpr int kright_lead_neo_number = 4;
constexpr int kleft_follow_neo_number = 2;
constexpr int kright_follow_neo_number = 5;
constexpr bool kleft_lead_is_inverted = false;
constexpr bool kright_lead_is_inverted = true;
} // namespace DriveConst

namespace MechanismConst {
constexpr int khopper_motor_top_port = 1;
constexpr int khopper_motor_bottom_port = 2;
constexpr int kelevator_motor_port = 6;
constexpr int kelevator_pnumatic_port = 0;
constexpr int kshooter_talon_port = 8;
} // namespace MechanismConst

namespace AutoConst {}
