#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long RAIN_DEFINITION_TAG = 'rain';
	extern s_tag_group rain_definition_group; // rain_definition_block


	extern s_tag_block_definition rain_definition_block;

	extern s_tag_struct_definition rain_definition_struct_definition; // tag group

	extern c_versioned_string_list rain_particle_flags_strings;
	extern s_string_list_definition rain_particle_flags;

	extern s_tag_reference_definition global_rain_definition_reference;

} // namespace macaque

} // namespace blofeld

