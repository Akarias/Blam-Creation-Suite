#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_STRUCT(particle_property_real_point3d_struct_new)
	{
		{ _field_char_enum, "Input Variable", &game_state_type_enum },
		{ _field_char_enum, "Range Variable", &game_state_type_enum },
		{ _field_char_enum, "Output Modifier", &output_mod_enum },
		{ _field_char_enum, "Output Modifier Input", &game_state_type_enum },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_real, "runtime m_constant_value!" },
		{ _field_word_integer, "runtime m_flags!" },
		{ _field_pad, "DSFDSGLKJ", 2 },
		{ _field_real_point_3d, "Starting interpolant" },
		{ _field_real_point_3d, "Ending interpolant" },
		{ _field_terminator }
	};

	TAG_STRUCT(particle_property_real_euler_angles2d_struct_new)
	{
		{ _field_char_enum, "Input Variable", &game_state_type_enum },
		{ _field_char_enum, "Range Variable", &game_state_type_enum },
		{ _field_char_enum, "Output Modifier", &output_mod_enum },
		{ _field_char_enum, "Output Modifier Input", &game_state_type_enum },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_real, "runtime m_constant_value!" },
		{ _field_word_integer, "runtime m_flags!" },
		{ _field_pad, "DSFDSGLKJ", 2 },
		{ _field_real_euler_angles_2d, "Direction at 0" },
		{ _field_real_euler_angles_2d, "Direction at 1" },
		{ _field_terminator }
	};

	TAG_STRUCT(particle_property_scalar_struct_new)
	{
		{ _field_char_enum, "Input Variable", &game_state_type_enum },
		{ _field_char_enum, "Range Variable", &game_state_type_enum },
		{ _field_char_enum, "Output Modifier", &output_mod_enum },
		{ _field_char_enum, "Output Modifier Input", &game_state_type_enum },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_real, "runtime m_constant_value!" },
		{ _field_word_integer, "runtime m_flags!" },
		{ _field_byte_flags, "force flags!", &force_flags_definition },
		{ _field_pad, "DSFDSGLKJ", 1 },
		{ _field_terminator }
	};

	TAG_STRUCT(particle_property_real_vector3d_struct_new)
	{
		{ _field_char_enum, "Input Variable", &game_state_type_enum },
		{ _field_char_enum, "Range Variable", &game_state_type_enum },
		{ _field_char_enum, "Output Modifier", &output_mod_enum },
		{ _field_char_enum, "Output Modifier Input", &game_state_type_enum },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_real, "runtime m_constant_value!" },
		{ _field_word_integer, "runtime m_flags!" },
		{ _field_pad, "DSFDSGLKJ", 2 },
		{ _field_real_vector_3d, "Starting interpolant" },
		{ _field_real_vector_3d, "Ending interpolant" },
		{ _field_terminator }
	};

	TAG_STRUCT(particle_property_color_struct_new)
	{
		{ _field_char_enum, "Input Variable", &game_state_type_enum },
		{ _field_char_enum, "Range Variable", &game_state_type_enum },
		{ _field_char_enum, "Output Modifier", &output_mod_enum },
		{ _field_char_enum, "Output Modifier Input", &game_state_type_enum },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_real, "runtime m_constant_value!" },
		{ _field_word_integer, "runtime m_flags!" },
		{ _field_pad, "DSFDSGLKJ", 2 },
		{ _field_terminator }
	};

	STRINGS(game_state_type_enum)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach, 18 },
		{ _field_version_greater_or_equal, _engine_type_halo2, 17 },
		"particle age",
		"particle emit time",
		"particle random 1",
		"particle random 2",
		"emitter age",
		"emitter random 1",
		"emitter random 2",
		"system lod",
		"game time",
		"effect a scale",
		"effect b scale",
		"particle rotation",
		"explosion animation",
		"explosion rotation",
		"particle random 3",
		"particle random 4",
		"location random",

		{ _field_version_equal, _engine_type_haloreach, 11 },
		"unknown bit 17",
		"unknown bit 18",
		"unknown bit 19",
		"unknown bit 20",
		"unknown bit 21",
		"unknown bit 22",
		"unknown bit 23",
		"unknown bit 24",
		"unknown bit 25",
		"unknown bit 26",
		"unknown bit 27",

		{ _field_version_greater_or_equal, _engine_type_halo4, 28 },
		"particle age",
		"system age{emitter age}",
		"particle random",
		"system random{emitter random}",
		"particle correlation 1{particle random 1}",
		"particle correlation 2{particle random 2}",
		"particle correlation 3{particle random 3}",
		"particle correlation 4{particle random 4}",
		"system correlation 1{emitter correlation 1}{emitter random 1}",
		"system correlation 2{emitter correlation 2}{emitter random 2}",
		"particle emission time{emitter time}{particle emit time}",
		"location lod{system lod}",
		"game time",
		"effect a scale",
		"effect b scale",
		"particle rotation{physics rotation}",
		"location random",
		"distance from emitter",
		"particle simulation a",
		"particle simulation b",
		"particle velocity",
		"invalid state --- please set again",
		{ _field_version_platform_include, _platform_type_pc, 5 },
		"unknown bit 23",
		"unknown bit 24",
		"unknown bit 25",
		"unknown bit 26",
		"unknown bit 27",
		"unknown bit 28",
	};
	STRING_LIST(game_state_type_enum, game_state_type_enum_strings, _countof(game_state_type_enum_strings));

	STRINGS(output_mod_enum$3)
	{
		" ",
		"Plus",
		"Times"
	};
	STRING_LIST(output_mod_enum$3, output_mod_enum$3_strings, _countof(output_mod_enum$3_strings));

	STRINGS(force_flags_definition)
	{
		"force constant"
	};
	STRING_LIST(force_flags_definition, force_flags_definition_strings, _countof(force_flags_definition_strings));

} // namespace blofeld

