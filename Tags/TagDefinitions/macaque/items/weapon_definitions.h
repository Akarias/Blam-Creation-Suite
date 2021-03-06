#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long WEAPON_TAG = 'weap';
	extern s_tag_group weapon_group; // weapon_block
	extern s_tag_block_definition weapon_block;
	extern s_tag_struct_definition weapon; // weapon_block


	extern s_tag_block_definition melee_damage_parameters_block;
	extern s_tag_struct_definition melee_damage_parameters_block_struct_definition; // melee_damage_parameters_block
	extern s_tag_block_definition globalAimAssistBlock_block;
	extern s_tag_struct_definition globalAimAssistBlock_block_struct_definition; // globalAimAssistBlock_block
	extern s_tag_block_definition globalAimSwimBlock_block;
	extern s_tag_struct_definition globalAimSwimBlock_block_struct_definition; // globalAimSwimBlock_block
	extern s_tag_block_definition weapon_first_person_interface_block;
	extern s_tag_struct_definition weapon_first_person_interface_block_struct_definition; // weapon_first_person_interface_block
	extern s_tag_block_definition magazines_block;
	extern s_tag_struct_definition magazines_block_struct_definition; // magazines_block
	extern s_tag_block_definition magazine_objects_block;
	extern s_tag_struct_definition magazine_objects_block_struct_definition; // magazine_objects_block
	extern s_tag_block_definition weapon_triggers_block;
	extern s_tag_struct_definition weapon_triggers_block_struct_definition; // weapon_triggers_block
	extern s_tag_block_definition weapon_barrels_block;
	extern s_tag_struct_definition weapon_barrels_block_struct_definition; // weapon_barrels_block
	extern s_tag_block_definition projectileDistributionCustomVector_block;
	extern s_tag_struct_definition projectileDistributionCustomVector_block_struct_definition; // projectileDistributionCustomVector_block
	extern s_tag_block_definition weapon_barrel_function_block;
	extern s_tag_struct_definition weapon_barrel_function_block_struct_definition; // weapon_barrel_function_block
	extern s_tag_block_definition weapon_barrel_first_person_offset_block;
	extern s_tag_struct_definition weapon_barrel_first_person_offset_block_struct_definition; // weapon_barrel_first_person_offset_block
	extern s_tag_block_definition barrel_firing_effect_block;
	extern s_tag_struct_definition barrel_firing_effect_block_struct_definition; // barrel_firing_effect_block
	extern s_tag_block_definition weapon_trigger_charging_fire_fraction_block;
	extern s_tag_struct_definition weapon_trigger_charging_fire_fraction_block_struct_definition; // weapon_trigger_charging_fire_fraction_block
	extern s_tag_block_definition weaponScaleshotStruct_block;
	extern s_tag_struct_definition weaponScaleshotStruct_block_struct_definition; // weaponScaleshotStruct_block
	extern s_tag_block_definition weaponScaleshotLevelStruct_block;
	extern s_tag_struct_definition weaponScaleshotLevelStruct_block_struct_definition; // weaponScaleshotLevelStruct_block
	extern s_tag_block_definition weapon_screen_effect_block;
	extern s_tag_struct_definition weapon_screen_effect_block_struct_definition; // weapon_screen_effect_block
	extern s_tag_block_definition WeaponSoundRTPCBlock_block;
	extern s_tag_struct_definition WeaponSoundRTPCBlock_block_struct_definition; // WeaponSoundRTPCBlock_block
	extern s_tag_block_definition WeaponSoundSweetenerBlock_block;
	extern s_tag_struct_definition WeaponSoundSweetenerBlock_block_struct_definition; // WeaponSoundSweetenerBlock_block

	extern s_tag_struct_definition aim_assist_struct;
	extern s_tag_struct_definition WeaponBarrelIronSightsStruct;
	extern s_tag_struct_definition weapon_interface_struct;
	extern s_tag_struct_definition weapon_shared_interface_struct;
	extern s_tag_struct_definition weapon_barrel_firing_parameters_struct;
	extern s_tag_struct_definition weapon_barrel_firing_error_struct;
	extern s_tag_struct_definition weapon_barrel_projectile_accuracy_penalty_struct;
	extern s_tag_struct_definition weapon_barrel_projectile_accuracy_penalty_function_struct;
	extern s_tag_struct_definition weapon_barrel_damage_effect_struct;
	extern s_tag_struct_definition weapon_trigger_autofire_struct;
	extern s_tag_struct_definition weapon_trigger_charging_struct;

	extern c_versioned_string_list magazine_flags_strings;
	extern s_string_list_definition magazine_flags;
	extern c_versioned_string_list barrel_prediction_type_enum_strings;
	extern s_string_list_definition barrel_prediction_type_enum;
	extern c_versioned_string_list weapon_barrel_flags_strings;
	extern s_string_list_definition weapon_barrel_flags;
	extern c_versioned_string_list weapon_barrel_distribution_functions_strings;
	extern s_string_list_definition weapon_barrel_distribution_functions;
	extern c_versioned_string_list weapon_trigger_inputs_strings;
	extern s_string_list_definition weapon_trigger_inputs;
	extern c_versioned_string_list weapon_trigger_overcharged_actions_strings;
	extern s_string_list_definition weapon_trigger_overcharged_actions;
	extern c_versioned_string_list weapon_trigger_behaviors_strings;
	extern s_string_list_definition weapon_trigger_behaviors;
	extern c_versioned_string_list weapon_trigger_autofire_actions_strings;
	extern s_string_list_definition weapon_trigger_autofire_actions;
	extern c_versioned_string_list trigger_prediction_type_enum_strings;
	extern s_string_list_definition trigger_prediction_type_enum;
	extern c_versioned_string_list weapon_trigger_definition_flags_strings;
	extern s_string_list_definition weapon_trigger_definition_flags;
	extern c_versioned_string_list weapon_trigger_charging_flags_strings;
	extern s_string_list_definition weapon_trigger_charging_flags;
	extern c_versioned_string_list weapon_definition_flags_strings;
	extern s_string_list_definition weapon_definition_flags;
	extern c_versioned_string_list weapon_definition_secondary_flags_strings;
	extern s_string_list_definition weapon_definition_secondary_flags;
	extern c_versioned_string_list secondary_trigger_modes_strings;
	extern s_string_list_definition secondary_trigger_modes;
	extern c_versioned_string_list movement_penalty_modes_strings;
	extern s_string_list_definition movement_penalty_modes;
	extern c_versioned_string_list weapon_types_strings;
	extern s_string_list_definition weapon_types;
	extern c_versioned_string_list first_time_pickup_types_strings;
	extern s_string_list_definition first_time_pickup_types;
	extern c_versioned_string_list global_melee_class_enum_definition_strings;
	extern s_string_list_definition global_melee_class_enum_definition;
	extern c_versioned_string_list weapon_screen_effect_flags_strings;
	extern s_string_list_definition weapon_screen_effect_flags;
	extern c_versioned_string_list weaponScaleshotLevelFlags_strings;
	extern s_string_list_definition weaponScaleshotLevelFlags;
	extern c_versioned_string_list weaponScaleshotFlags_strings;
	extern s_string_list_definition weaponScaleshotFlags;

	extern s_tag_reference_definition global_weapon_reference;
	extern s_tag_reference_definition crate_projectile_reference;

} // namespace macaque

} // namespace blofeld

