#pragma once

namespace blofeld
{


extern s_tag_struct effect_locations_block_struct_definition;
extern s_tag_block_definition effect_locations_block;
extern s_tag_struct effect_event_block_struct_definition;
extern s_tag_block_definition effect_event_block;
extern s_tag_struct effect_part_block_struct_definition;
extern s_tag_block_definition effect_part_block;
extern s_tag_struct effect_accelerations_block_struct_definition;
extern s_tag_block_definition effect_accelerations_block;
extern s_tag_struct effect_looping_sound_block_struct_struct_definition;
extern s_tag_block_definition effect_looping_sound_block;
extern s_tag_struct effect_conical_distribution_block_struct_definition;
extern s_tag_block_definition effect_conical_distribution_block;

constexpr unsigned long EFFECT_TAG = 'effe';

extern s_tag_block_definition effect_block;
extern s_tag_group effect_group;
} // namespace blofeld
