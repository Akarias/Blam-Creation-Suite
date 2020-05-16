#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(multiplayer_globals_struct_definition)
{
	FIELD( _field_block, "universal", &multiplayer_universal_block ),
	FIELD( _field_block, "runtime", &multiplayer_runtime_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(spawn_influence_weight_falloff_function_block, 1)
{
	FIELD( _field_struct, "function", &scalar_function_named_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(multiplayer_universal_block, 1)
{
	FIELD( _field_tag_reference, "random player names" ),
	FIELD( _field_tag_reference, "team names" ),
	FIELD( _field_block, "teams", &teamDefinitionBlock ),
	FIELD( _field_tag_reference, "multiplayer text" ),
	FIELD( _field_tag_reference, "sandbox text" ),
	FIELD( _field_tag_reference, "sandbox object properties values" ),
	FIELD( _field_tag_reference, "effects" ),
	FIELD( _field_block, "multiplayer roles", &global_team_role_block ),
	FIELD( _field_block, "requisition constants", &requisition_constants_block ),
	FIELD( _field_block, "player starting profile", &scenario_profiles_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(teamDefinitionBlock, k_multiplayer_team_game_team_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_real_rgb_color, "primary color" ),
	FIELD( _field_real_rgb_color, "secondary color" ),
	FIELD( _field_custom, "- Emblem Data" ),
	FIELD( _field_byte_integer, "foreground emblem index" ),
	FIELD( _field_byte_integer, "background emblem index" ),
	FIELD( _field_byte_flags, "info flags" ),
	FIELD( _field_char_enum, "primary color index" ),
	FIELD( _field_char_enum, "secondary color index" ),
	FIELD( _field_char_enum, "background color index" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(requisition_constants_block, 1)
{
	FIELD( _field_real, "FTL bonus fraction#multiplier to apply to money earned by minions to also give to the fireteam leader" ),
	FIELD( _field_explanation, "AWARD AMOUNTS" ),
	FIELD( _field_long_integer, "Kill" ),
	FIELD( _field_long_integer, "Assist" ),
	FIELD( _field_long_integer, "Fire team leader kill" ),
	FIELD( _field_long_integer, "vehicle kill#Default, only applies if the vehicle doesn\'t have a custom award amount in the scenario requisition palette." ),
	FIELD( _field_long_integer, "objective destroyed#awarded to entire team" ),
	FIELD( _field_long_integer, "objective armed#awarded to entire team" ),
	FIELD( _field_long_integer, "objective disarmed#awarded to entire team" ),
	FIELD( _field_long_integer, "objective defending#awarded every 3 seconds to any individuals near secondary defensive objectives" ),
	FIELD( _field_long_integer, "neutral territory owned#awarded every 3 seconds to entire team that owns BFG" ),
	FIELD( _field_long_integer, "served as reinforcement target#awarded to a reinforcement target when a teammate spawns on him (to encourage cooperation)" ),
	FIELD( _field_long_integer, "uberassault gun captured#awarded on gaining ownership of a gun to every member of the new owning team" ),
	FIELD( _field_long_integer, "uberassault gun owned#awarded every 3 seconds to the entire team that owns this gun.  Money from multiple guns stacks (so if you own all 3, you\'ll get 3x this money every 3 seconds)." ),
	FIELD( _field_explanation, "PENALTY AMOUNTS" ),
	FIELD( _field_long_integer, "Betrayed a teammate" ),
	FIELD( _field_explanation, "FIRE TEAM TIER KILL REQUIREMENTS" ),
	FIELD( _field_long_integer, "Bronze kill minimum" ),
	FIELD( _field_long_integer, "Silver kill minimum" ),
	FIELD( _field_long_integer, "Gold kill minimum" ),
	FIELD( _field_explanation, "FIRE TEAM TIER BONUS MULTIPLIERS" ),
	FIELD( _field_real, "Bronze multiplier" ),
	FIELD( _field_real, "Silver multiplier" ),
	FIELD( _field_real, "Gold multiplier" ),
	FIELD( _field_explanation, "FIRE TEAM TIER TIME REQUIREMENT" ),
	FIELD( _field_long_integer, "Bronze advancement time" ),
	FIELD( _field_long_integer, "Silver advancement time" ),
	FIELD( _field_long_integer, "Gold advancement time" ),
	FIELD( _field_block, "Requisition palette", &requisition_palette_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(requisition_palette_block, k_infinity_requisition_palette_maximum_count)
{
	FIELD( _field_explanation, "CUSTOM APPS" ),
	FIELD( _field_tag_reference, "name" ),
	FIELD( _field_string_id, "display_name^" ),
	FIELD( _field_long_enum, "special_buy" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(multiplayer_runtime_block, 1)
{
	FIELD( _field_tag_reference, "editor biped" ),
	FIELD( _field_tag_reference, "editor helper" ),
	FIELD( _field_tag_reference, "flag" ),
	FIELD( _field_tag_reference, "ball" ),
	FIELD( _field_tag_reference, "assault bomb" ),
	FIELD( _field_tag_reference, "vip influence area" ),
	FIELD( _field_tag_reference, "in game text" ),
	FIELD( _field_block, "sounds", &sounds_block ),
	FIELD( _field_block, "looping sounds", &looping_sounds_block ),
	FIELD( _field_tag_reference, "megalo sounds{english}" ),
	FIELD( _field_tag_reference, "communication sounds{comm english}" ),
	FIELD( _field_long_integer, "maximum frag count" ),
	FIELD( _field_long_integer, "maximum plasma count" ),
	FIELD( _field_block, "multiplayer constants", &multiplayer_constants_block ),
	FIELD( _field_block, "state responses", &game_engine_status_response_block ),
	FIELD( _field_tag_reference, "scoreboard emblem bitmap" ),
	FIELD( _field_tag_reference, "scoreboard dead emblem bitmap" ),
	FIELD( _field_tag_reference, "hill shader" ),
	FIELD( _field_tag_reference, "default_biped_simulation_interpolation" ),
	FIELD( _field_tag_reference, "default_vehicle_simulation_interpolation" ),
	FIELD( _field_tag_reference, "default_crate_simulation_interpolation" ),
	FIELD( _field_tag_reference, "default_item_simulation_interpolation" ),
	FIELD( _field_tag_reference, "default_projectile_simulation_interpolation" ),
	FIELD( _field_tag_reference, "default_object_simulation_interpolation" ),
	FIELD( _field_tag_reference, "co-op spawning globals" ),
	FIELD( _field_tag_reference, "megalo string_id table" ),
	FIELD( _field_tag_reference, "killcam parameters# Used for non projectile killcams." ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sounds_block, k_maximum_multiplayer_sounds)
{
	FIELD( _field_tag_reference, "sound^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(looping_sounds_block, k_maximum_multiplayer_sounds)
{
	FIELD( _field_tag_reference, "looping sound^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(multiplayer_constants_block, 1)
{
	FIELD( _field_explanation, "PLAYER SPAWN INFLUENCERS" ),
	FIELD( _field_tag_reference, "Default Spawn Settings" ),
	FIELD( _field_explanation, "MORE MP CONSTANTS" ),
	FIELD( _field_real, "teleporter recharge time:seconds" ),
	FIELD( _field_tag_reference, "sandbox effect" ),
	FIELD( _field_string_id, "blocked teleporter string" ),
	FIELD( _field_explanation, "RESPAWN STRINGS" ),
	FIELD( _field_string_id, "voluntary respawn control instructions" ),
	FIELD( _field_string_id, "spawn allowed default respawn" ),
	FIELD( _field_string_id, "spawn at player allowed looking at self" ),
	FIELD( _field_string_id, "spawn at player allowed looking at target" ),
	FIELD( _field_string_id, "spawn at player allowed looking at potential target" ),
	FIELD( _field_string_id, "spawn at territory allowed looking at target" ),
	FIELD( _field_string_id, "spawn at territory allowed looking at potential target" ),
	FIELD( _field_string_id, "you are out of lives" ),
	FIELD( _field_string_id, "invalid spawn target selected" ),
	FIELD( _field_string_id, "targetted player enemies nearby" ),
	FIELD( _field_string_id, "targetted player unfriendly team" ),
	FIELD( _field_string_id, "targetted player dead" ),
	FIELD( _field_string_id, "targetted player in combat" ),
	FIELD( _field_string_id, "targetted player too far from owned flag" ),
	FIELD( _field_string_id, "no available netpoints" ),
	FIELD( _field_string_id, "targetted netpoint contested" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_engine_status_response_block, k_maximum_status_response_count)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "FAW", 2 ),
	FIELD( _field_enum, "state^" ),
	FIELD( _field_pad, "BNYFIDDGX", 2 ),
	FIELD( _field_string_id, "ffa message" ),
	FIELD( _field_string_id, "team message" ),
	FIELD( _field_tag_reference, "unused!" ),
	FIELD( _field_pad, "GTL", 4 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(multiplayer_color_block$3, 32)
{
	FIELD( _field_real_rgb_color, "color" ),
	FIELD( _field_terminator )
};

TAG_GROUP(multiplayer_globals_block, MULTIPLAYER_GLOBALS_TAG)
{
	FIELD( _field_block, "universal", &multiplayer_universal_block ),
	FIELD( _field_block, "runtime", &multiplayer_runtime_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld
