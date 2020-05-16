#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(scenario_interpolator, SCENARIO_INTERPOLATOR_TAG, scenario_interpolator_block_block );

TAG_BLOCK_FROM_STRUCT(scenario_interpolator_block, 1, scenario_interpolator_struct_definition_struct_definition );

TAG_BLOCK(scenario_interpolator_data_block, k_maximum_interpolators_per_scenario)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "SCBP1", 2 ),
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_struct, "function", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_real, "duration:seconds" ),
	FIELD( _field_long_enum, "map reset type" ),
	FIELD( _field_real_fraction, "custom map reset value" ),
	FIELD( _field_long_enum, "start type" ),
	FIELD( _field_long_enum, "stop type" ),
	FIELD( _field_real_fraction, "custom stop value" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scenario_interpolator_struct_definition)
{
	FIELD( _field_block, "interpolators", &scenario_interpolator_data_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

