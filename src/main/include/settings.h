#pragma once

namespace Joy0Const {
constexpr int kquick_turn_button = 1;
constexpr int kdrive_speed_axis = 1;
constexpr int kdrive_curvature_axis = 1;
} // namespace Joy0Const

namespace Joy1Const {
constexpr int elevator_slow_multiplier = 0.5;
}

namespace SensorConst {
constexpr int kbreak_beam_port = 0;
constexpr int limit_switch_top_port = 1;
constexpr int limit_switch_bottom_port = 2;
}

namespace DriveConst {
constexpr int kleft_lead_neo_number = 3;
constexpr int kright_lead_neo_number = 4;
constexpr int kleft_follow_neo_number = 2;
constexpr int kright_follow_neo_number = 5;
} // namespace DriveConst

namespace MechanismConst {
constexpr int kelevator_motor_port = 6;
constexpr int climb_amperage = 10;
}

namespace AutoConst {}
