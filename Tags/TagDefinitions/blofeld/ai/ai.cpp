#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_STRUCT(ai_spawn_conditions_struct)
	{
		{ _field_legacy, _field_word_flags, "difficulty flags", &global_campaign_difficulty_enum },
		{ _field_legacy, _field_pad, "post-difficulty-flags-padding", 2 },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_legacy, _field_short_integer, "unknown@" },
		{ _field_legacy, _field_short_integer, "unknown@" },
		{ _field_legacy, _field_short_integer, "unknown&" },
		{ _field_legacy, _field_short_integer, "unknown&" },

		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

