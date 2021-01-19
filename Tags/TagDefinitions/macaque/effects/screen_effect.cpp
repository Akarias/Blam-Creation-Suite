#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		area_screen_effect_group,
		AREA_SCREEN_EFFECT_TAG,
		nullptr,
		INVALID_TAG,
		area_screen_effect_block );

	TAG_BLOCK_FROM_STRUCT(
		area_screen_effect_block,
		"area_screen_effect_block",
		1,
		area_screen_effect_struct_definition);

	#define SINGLE_SCREEN_EFFECT_ID { 0x2E559B36, 0x4E3546A7, 0xA1AE1E29, 0x90AA239F }
	TAG_BLOCK(
		single_screen_effect_block,
		"single_screen_effect",
		s_area_screen_effect_definition::k_maximum_effects_per_tag,
		"s_single_screen_effect_definition",
		SINGLE_SCREEN_EFFECT_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_word_flags, "flags", &area_screen_effect_flags_definition },
		{ _field_word_flags, "hidden flags!", &area_screen_effect_hidden_flags_definition },
		{ _field_explanation, "DISTANCE FALLOFF", "controls the maximum distance and the distance falloff of this effect\nNOTE: not used for scenario global effects" },
		{ _field_real, "maximum distance:world units#the maximum distance this screen effect will affect" },
		{ _field_struct, "distance falloff", &screen_effect_scalar_function_struct },
		{ _field_explanation, "TIME EVOLUTION", "controls the lifetime and time falloff of this effect\nNOTE: not used for scenario global effects" },
		{ _field_real, "delay:seconds#the effect will start after this many seconds (ignored if the play sequentially flag is set)" },
		{ _field_real, "lifetime:seconds#the effect is destroyed after this many seconds (0 = never dies)" },
		{ _field_struct, "time falloff", &screen_effect_scalar_function_struct },
		{ _field_explanation, "ANGLE FALLOFF", "controls the falloff of this effect based on how close you are to looking directly at it\nNOTE: not used for scenario global effects" },
		{ _field_struct, "angle falloff", &screen_effect_scalar_function_struct },
		{ _field_explanation, "OBJECT FALLOFF", "applies a falloff based on an object function - ignored if the effect is not attached to an object" },
		{ _field_struct, "object falloff", &screen_effect_scalar_object_function_struct },
		{ _field_explanation, "EFFECTS", "a selection of effects to choose from\nin the case of overlapping effects, the maximum will be taken" },
		{ _field_tag_reference, "color grading look-up-texture", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },
		{ _field_real, "runtime color grading strength!:[do not edit]#do not edit" },
		{ _field_real, "exposure boost:stops#increase in exposure" },
		{ _field_real, "exposure deboost:stops#decrease in exposure" },
		{ _field_real, "hue left:degrees [0-360]#shifts hue R->G->B" },
		{ _field_real, "hue right:degrees [0-360]#shifts hue B->G->R" },
		{ _field_real, "saturation:[0-1]#increases saturation" },
		{ _field_real, "desaturation:[0-1]#decreases saturation" },
		{ _field_real, "contrast enhance:[0-1]#contrast increase" },
		{ _field_real, "gamma enhance:[0-10]#gamma increase" },
		{ _field_real, "gamma reduce:[0-10]#gamma increase" },
		{ _field_real, "bright noise:[0-1]#add bright noise contribution, 0 turns it off, 1: full on" },
		{ _field_real, "dark noise:[0-1]#add dark noise contribution, 0 turns it off, 1: full on" },
		{ _field_real_rgb_color, "color filter#this color is multiplied on top" },
		{ _field_real_rgb_color, "color floor#this color is subtracted" },
		{ _field_real_fraction, "color replace strength:[0-1]#used to blend in the color replace below" },
		{ _field_real_rgb_color, "color replace#this color is blended in place of the screen\'s color" },
		{ _field_real, "tron:[0-1]#adds a full-screen tron effect" },
		{ _field_real, "motion suck:[-2, 2]#adds motion-blur towards or away from this screen effect" },
		{ _field_real, "bloom buffer motion suck:[-2, 2]#adds cheap bloom buffer motion-blur towards or away from this screen effect" },
		{ _field_real_vector_3d, "motion suck direction!:[do not edit]#do not edit" },
		{ _field_real, "horizontal blur:[0-10] expensive#blurs the entire screen" },
		{ _field_real, "vertical blur:[0-10] expensive#blurs the entire screen" },
		{ _field_real, "vision mode:[0-1]#turns on the global vision mode" },
		{ _field_real, "hud fade:[0-1]#fades the chud" },
		{ _field_real, "fov in:[0-1]#zooms in the field of view" },
		{ _field_real, "fov out:[0-1]#zooms out the field of view" },
		{ _field_real, "screen shake:[0-1]#shakes the entire screen" },
		{ _field_tag_reference, "shader effect#applies this shader to the entire screen", &global_screen_shader_reference },
		{ _field_terminator }
	};

	#define AREA_SCREEN_EFFECT_STRUCT_DEFINITION_ID { 0xE25095D4, 0x57E84346, 0xAA15B7AB, 0x8088091E }
	TAG_STRUCT(
		area_screen_effect_struct_definition,
		"area_screen_effect_struct_definition",
		"s_area_screen_effect_definition",
		AREA_SCREEN_EFFECT_STRUCT_DEFINITION_ID)
	{
		{ _field_word_flags, "global flags", &area_screen_effect_global_flags_definition },
		{ _field_word_flags, "global hidden flags!", &area_screen_effect_global_hidden_flags_definition },
		{ _field_block, "screen effects", &single_screen_effect_block },
		{ _field_terminator }
	};

	#define SCREEN_EFFECT_SCALAR_FUNCTION_STRUCT_ID { 0xD2D2C2B8, 0xA3D24359, 0x8D127DD8, 0x7EB7F3D8 }
	TAG_STRUCT(
		screen_effect_scalar_function_struct,
		"screen_effect_scalar_function_struct",
		"s_screen_effect_scalar_function",
		SCREEN_EFFECT_SCALAR_FUNCTION_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	#define SCREEN_EFFECT_SCALAR_OBJECT_FUNCTION_STRUCT_ID { 0x92C128E6, 0x4B424665, 0x80E1707B, 0xCE6CDB1D }
	TAG_STRUCT(
		screen_effect_scalar_object_function_struct,
		"screen_effect_scalar_object_function_struct",
		"s_screen_effect_scalar_object_function",
		SCREEN_EFFECT_SCALAR_OBJECT_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable!", nullptr, 'fnin' },
		{ _field_string_id, "Range Variable!", nullptr, 'fnir' },
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	STRINGS(area_screen_effect_global_flags_definition)
	{
		"play sequentially - ignore delay settings",
		"debug this screen effect",
		"force delete when attached to dead object",
		"force max one per object",
		"force looping (dangerous; lasts forever)",
		"only spawn killcam version during killcam"
	};
	STRING_LIST(area_screen_effect_global_flags_definition, area_screen_effect_global_flags_definition_strings, _countof(area_screen_effect_global_flags_definition_strings));

	STRINGS(area_screen_effect_global_hidden_flags_definition)
	{
		"update thread",
		"render thread"
	};
	STRING_LIST(area_screen_effect_global_hidden_flags_definition, area_screen_effect_global_hidden_flags_definition_strings, _countof(area_screen_effect_global_hidden_flags_definition_strings));

	STRINGS(area_screen_effect_flags_definition)
	{
		"debug disable",
		"allow effect outside radius",
		"unattached",
		"first person{first person only}",
		"third person{third person only}",
		"disable camera falloffs{cinematic}#disables distance and angle falloffs",
		"only affects attached object",
		"draw precisely one (ask Bill before you check this)"
	};
	STRING_LIST(area_screen_effect_flags_definition, area_screen_effect_flags_definition_strings, _countof(area_screen_effect_flags_definition_strings));

	STRINGS(area_screen_effect_hidden_flags_definition)
	{
		"update thread",
		"render thread"
	};
	STRING_LIST(area_screen_effect_hidden_flags_definition, area_screen_effect_hidden_flags_definition_strings, _countof(area_screen_effect_hidden_flags_definition_strings));

	TAG_REFERENCE(global_area_screen_effect_reference, AREA_SCREEN_EFFECT_TAG);

	TAG_REFERENCE(global_screen_shader_reference, MATERIAL_TAG);

} // namespace macaque

} // namespace blofeld

