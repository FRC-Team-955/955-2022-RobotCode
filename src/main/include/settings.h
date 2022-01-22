#pragma once

#include <units/acceleration.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>


namespace Joy0Const {
constexpr int kquick_turn_button = 1;
constexpr int kdrive_speed_axis = 1;
constexpr int kdrive_curvature_axis = 1;
constexpr int kreverse_drive = 4;
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

namespace MechanismConst {}

namespace AutoConst {
constexpr units::meter_t ktrack_width_meters = 1_m;
constexpr units::meter_t kwheel_diameter_meters = 0.1524_m;
constexpr double kgear_ratio = 10.75;

constexpr units::volt_t kS = 0.268_V;
constexpr auto kV = 1.89_V/ 1_mps;
//constexpr u kA = 0.243_volts * seconds^2 / distance;
constexpr units::meters_per_second_t kmax_velocity = 2_mps;
constexpr units::meters_per_second_squared_t kmax_acceleration = 2_mps_sq;
}
