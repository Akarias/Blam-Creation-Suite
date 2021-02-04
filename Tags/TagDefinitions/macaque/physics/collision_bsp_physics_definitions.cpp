#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define COLLISION_BSP_PHYSICS_BLOCK_ID { 0x5B8E7B3A, 0xC8394498, 0xB6AE249F, 0x4C00F83F }
	TAG_BLOCK(
		collision_bsp_physics_block,
		"collision_bsp_physics_block",
		(1024),
		"s_collision_bsp_physics_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		COLLISION_BSP_PHYSICS_BLOCK_ID,
		4)
	{
		{ _field_struct, "collision bsp shape", &collision_geometry_shape_struct },
		{ _field_struct, "mopp bv tree shap", &mopp_bv_tree_shape_struct },
		{ _field_terminator }
	};

	#define COLLISION_GEOMETRY_SHAPE_STRUCT_ID { 0x97B622E0, 0xF8AF48BA, 0x85446709, 0x0386FA88 }
	TAG_STRUCT(
		collision_geometry_shape_struct,
		"collision_geometry_shape_struct",
		"c_collision_geometry_shape",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		COLLISION_GEOMETRY_SHAPE_STRUCT_ID,
		4)
	{
		{ _field_struct, "base", &havok_shape_collection_struct_2010_2 },
		FIELD_PAD("foobar666", nullptr, 8),
		{ _field_real_vector_3d, "center" },
		{ _field_real, "havok w center" },
		{ _field_real_vector_3d, "half extent" },
		{ _field_real, "havok w half extent" },
		{ _field_long_integer, "runtime model definition tag index" },
		{ _field_long_integer, "collision bsp reference pointer0", _field_id_zero_data },
		{ _field_long_integer, "collision bsp reference pointer1", _field_id_zero_data },
		{ _field_char_integer, "structure_bsp_index" },
		{ _field_char_integer, "collision geometry shape type" },
		{ _field_short_integer, "instance index" },
		{ _field_real, "scale" },
		FIELD_PAD("3 long pad", nullptr, 12),
		{ _field_terminator }
	};

	#define MOPP_BV_TREE_SHAPE_STRUCT_ID { 0x662B38A4, 0xAAAC448C, 0x81C491AB, 0xA4E2A6EE }
	TAG_STRUCT(
		mopp_bv_tree_shape_struct,
		"mopp_bv_tree_shape_struct",
		"c_mopp_bv_tree_shape",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		MOPP_BV_TREE_SHAPE_STRUCT_ID,
		4)
	{
		{ _field_struct, "mopp bv tree shape", &havok_shape_struct_2010_2 },
		FIELD_PAD("m_bvTreeType", nullptr, 1),
		FIELD_PAD("3 other bytes", nullptr, 3),
		{ _field_long_integer, "mopp code pointer", _field_id_zero_data },
		{ _field_long_integer, "mopp data skip", _field_id_zero_data },
		{ _field_long_integer, "mopp data size" },
		{ _field_real_vector_3d, "code info copy" },
		{ _field_real, "havok w code info copy" },
		{ _field_long_integer, "child shape vtable", _field_id_zero_data },
		{ _field_long_integer, "child shape pointer", _field_id_zero_data },
		{ _field_long_integer, "child size" },
		FIELD_PAD("mopp alignment", nullptr, 4),
		{ _field_real, "mopp scale" },
		FIELD_PAD("final pad", nullptr, 12),
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld
