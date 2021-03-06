#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(jetwash_definition_block, k_maximum_jetwash_points_per_object)
	{
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "marker name^" },
		{ _field_legacy, _field_real, "radius" },
		{ _field_legacy, _field_long_integer, "maximum traces!:traces per second" },
		{ _field_legacy, _field_real, "maximum emission length:world units" },
		{ _field_legacy, _field_angle_bounds, "trace yaw angle: degrees" },
		{ _field_legacy, _field_angle_bounds, "trace pitch angle: degrees" },
		{ _field_legacy, _field_real, "particle offset:world units" },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

