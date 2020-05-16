#pragma once

namespace blofeld
{

constexpr unsigned long VEHICLE_TAG = 'vehi';

extern s_tag_group vehicle_group;

extern s_tag_block_definition vehicle_block_block;
extern s_tag_block_definition human_tank_block_block;
extern s_tag_struct human_jeep_block_block_struct;
extern s_tag_block_definition human_jeep_block_block;
extern s_tag_struct human_plane_block_block_struct;
extern s_tag_block_definition human_plane_block_block;
extern s_tag_struct wolverine_block_block_struct;
extern s_tag_block_definition wolverine_block_block;
extern s_tag_struct alien_scout_block_block_struct;
extern s_tag_block_definition alien_scout_block_block;
extern s_tag_struct alien_fighter_block_block_struct;
extern s_tag_block_definition alien_fighter_block_block;
extern s_tag_struct turret_block_block_struct;
extern s_tag_block_definition turret_block_block;
extern s_tag_struct mantis_block_block_struct;
extern s_tag_block_definition mantis_block_block;
extern s_tag_struct vtol_block_block_struct;
extern s_tag_block_definition vtol_block_block;
extern s_tag_struct vtol_speed_interpolated_block_block_struct;
extern s_tag_block_definition vtol_speed_interpolated_block_block;
extern s_tag_struct chopper_block_block_struct;
extern s_tag_block_definition chopper_block_block;
extern s_tag_struct guardian_block_block_struct;
extern s_tag_block_definition guardian_block_block;
extern s_tag_struct jackal_glider_block_block_struct;
extern s_tag_block_definition jackal_glider_block_block;
extern s_tag_struct boat_block_block_struct;
extern s_tag_block_definition boat_block_block;
extern s_tag_struct space_fighter_block_block_struct;
extern s_tag_block_definition space_fighter_block_block;
extern s_tag_struct revenant_block_block_struct;
extern s_tag_block_definition revenant_block_block;
extern s_tag_struct SoundRTPCBlock_block_struct;
extern s_tag_block_definition SoundRTPCBlock_block;
extern s_tag_struct SoundSweetenerBlock_block_struct;
extern s_tag_block_definition SoundSweetenerBlock_block;
extern s_tag_struct physics_transitions_block_block_struct;
extern s_tag_block_definition physics_transitions_block_block;

extern s_tag_struct vehicle_group_struct_definition; // tag group
extern s_tag_struct vehicle_physics_types_struct_struct_definition;
extern s_tag_struct human_tank_struct_struct_definition;
extern s_tag_struct vehicle_steering_control_struct_struct_definition;
extern s_tag_struct vehicle_turning_control_struct_struct_definition;
extern s_tag_struct steering_animation_struct_struct_definition;
extern s_tag_struct engine_function_struct_struct_definition;
extern s_tag_struct vtol_descent_function_struct_struct_definition;
extern s_tag_struct flight_surface_struct_struct_definition;
extern s_tag_struct jackal_glider_drag_struct_struct_definition;

} // namespace blofeld

