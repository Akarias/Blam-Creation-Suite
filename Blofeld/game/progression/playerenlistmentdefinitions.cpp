#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(player_enlistment_globals_definition_struct_definition)
{
	FIELD( _field_explanation, "Enlistments" ),
	FIELD( _field_block, "enlistments", &playerEnlistmentDefinitionBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(playerEnlistmentDefinitionBlock, k_maximumPlayerEnlistments - 1)
{
	FIELD( _field_string_id, "name#the string id of the name of this enlistment" ),
	FIELD( _field_string_id, "description#the string id of the description of this enlistment" ),
	FIELD( _field_short_integer, "sprite index#the sprite index of the icon for this enlistment" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "PAD0", 1 ),
	FIELD( _field_string_id, "unlocked emblem fg" ),
	FIELD( _field_string_id, "unlocked emblem bg" ),
	FIELD( _field_string_id, "unlocked helmet" ),
	FIELD( _field_string_id, "unlocked chest" ),
	FIELD( _field_string_id, "unlocked left shoulder" ),
	FIELD( _field_string_id, "unlocked right shoulder" ),
	FIELD( _field_string_id, "unlocked arms" ),
	FIELD( _field_string_id, "unlocked legs" ),
	FIELD( _field_string_id, "unlocked visor" ),
	FIELD( _field_block, "grades#the grades that define the leveling track for this enlistment", &player_grade_definition_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(player_enlistment_globals_definition_block, PLAYER_ENLISTMENT_GLOBALS_DEFINITION_TAG)
{
	FIELD( _field_explanation, "Enlistments" ),
	FIELD( _field_block, "enlistments", &playerEnlistmentDefinitionBlock ),
	FIELD( _field_terminator )
};

} // namespace blofeld
