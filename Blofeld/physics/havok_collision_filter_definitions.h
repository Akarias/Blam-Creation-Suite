#pragma once

namespace blofeld
{

extern s_tag_struct havok_collision_filter_struct_definition_struct_definition;
extern s_tag_struct havok_group_filter_filter_struct_struct_definition;

extern s_tag_struct havok_collision_filter_group_block_struct_definition;
extern s_tag_block_definition havok_collision_filter_group_block;

constexpr unsigned long HAVOK_COLLISION_FILTER_TAG = 'hcfd';

extern s_tag_block_definition havok_collision_filter_block;
extern s_tag_group havok_collision_filter_group;
} // namespace blofeld
