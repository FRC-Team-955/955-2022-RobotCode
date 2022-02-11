#pragma once
#include <units/acceleration.h>
#include <units/velocity.h>

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
//Basic robot measurements
constexpr units::meter_t ktrack_width_meters = 0.5842_m;
constexpr units::meter_t kwheel_diameter_meters = 0.1524_m;
constexpr double kgear_ratio = 10.75;

//the PID values for the left and right PID Controllers
constexpr double kP =1.9398;
constexpr double kI =0.0;
constexpr double kD =0.0;

//the feedforward values
constexpr units::volt_t kS = 0.10023_V;
constexpr auto kV = 1.2794_V/ 1_mps;
constexpr auto kA = 1.2494_V/1_mps_sq;

//TrajectoryConfig values
constexpr units::meters_per_second_t kmax_velocity = 2_mps;
constexpr units::meters_per_second_squared_t kmax_acceleration = 2_mps_sq;
constexpr units::second_t timerss= 2_s;
}
