#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP(pathfinding, PATHFINDING_TAG)
	{
		{ _field_legacy, _field_block, "bsp pathfinding data", &pathfinding_data_block_block },
		{ _field_legacy, _field_block, "mobileNavMeshes*~", &MobileNavMeshBlock_block },
		{ _field_legacy, _field_block, "navVolumes*~", &NavVolumeBlock_block },
		{ _field_legacy, _field_block, "navClimbs*~", &NavClimbBlock_block },
		{ _field_legacy, _field_block, "user edges*~", &user_edge_block_block },
		{ _field_legacy, _field_block, "hints", &user_hint_block_block },
		{ _field_legacy, _field_byte_integer, "already Converted!" },
		{ _field_legacy, _field_pad, "fuckPad", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(FaceUserDataBlock, 256*1024)
	{
		{ _field_legacy, _field_short_integer, "m_flags*~" },
		{ _field_legacy, _field_pad, "pad", 2 },
		{ _field_legacy, _field_real, "currentMinPathDistance!*~" },
		{ _field_legacy, _field_real, "currentMinTargetApproachDistance!*~" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(pathfinding_data_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		{ _field_legacy, _field_long_integer, "runtimeNavMesh*~!" },
		{ _field_legacy, _field_long_integer, "runtimeNavGraph*~!" },
		{ _field_legacy, _field_long_integer, "runtimeNavMediator*~!" },
		{ _field_legacy, _field_pad, "pads", 4 },
		{ _field_legacy, _field_data, "navGraphData*~" },
		{ _field_legacy, _field_data, "navMediatorData*~" },
		{ _field_legacy, _field_block, "faceUserData*~", &FaceUserDataBlock_block },
		{ _field_legacy, _field_long_integer, "structure checksum*~" },
		{ _field_legacy, _field_pad, "pads2", 8 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(MobileNavMeshBlock, MAX_NUM_MOBILE_NAVMESHES)
	{
		{ _field_legacy, _field_long_integer, "runtimeNavMesh*~!" },
		{ _field_legacy, _field_long_integer, "runtimeNavGraph*~!" },
		{ _field_legacy, _field_long_integer, "runtimeNavMediator*~!" },
		{ _field_legacy, _field_pad, "pads2", 4 },
		{ _field_legacy, _field_data, "navGraphData*~" },
		{ _field_legacy, _field_data, "navMediatorData*~" },
		{ _field_legacy, _field_block, "faceUserData*~", &FaceUserDataBlock_block },
		{ _field_legacy, _field_struct, "object id", &scenario_object_id_struct_struct_definition },
		{ _field_legacy, _field_byte_flags, "flags", &MobileNavMeshFlagsDefinition },
		{ _field_legacy, _field_pad, "pads", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(NavVolumeBlock, MAX_NUM_NAV_VOLUMES)
	{
		{ _field_legacy, _field_short_integer, "zoneIndex*~" },
		{ _field_legacy, _field_short_integer, "areaIndex*~" },
		{ _field_legacy, _field_long_integer, "runtimeNavVolume*~!" },
		{ _field_legacy, _field_long_integer, "runtimeNavMediator*~!" },
		{ _field_legacy, _field_data, "navMediatorData*~" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(NavClimbBlock, MAX_NUM_NAV_CLIMBS)
	{
		{ _field_legacy, _field_long_integer, "runtimeNavMesh*~!" },
		{ _field_legacy, _field_long_integer, "runtimeNavGraph*~!" },
		{ _field_legacy, _field_long_integer, "runtimeNavMediator*~!" },
		{ _field_legacy, _field_pad, "pads", 4 },
		{ _field_legacy, _field_data, "navGraphData*~" },
		{ _field_legacy, _field_data, "navMediatorData*~" },
		{ _field_legacy, _field_block, "faceUserData*~", &FaceUserDataBlock_block },
		{ _field_legacy, _field_short_integer, "zoneIndex*~" },
		{ _field_legacy, _field_short_integer, "areaIndex*~" },
		{ _field_legacy, _field_pad, "pads2", 8 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(user_edge_block, 4*1024)
	{
		{ _field_legacy, _field_real_vector_3d, "m_x*~" },
		{ _field_legacy, _field_real, "havok w m_x*~!" },
		{ _field_legacy, _field_real_vector_3d, "m_y*~" },
		{ _field_legacy, _field_real, "havok w m_y*~!" },
		{ _field_legacy, _field_real_vector_3d, "m_z*~" },
		{ _field_legacy, _field_real, "havok w m_z*~!" },
		{ _field_legacy, _field_long_integer, "m_meshUidA*~" },
		{ _field_legacy, _field_long_integer, "m_meshUidB*~" },
		{ _field_legacy, _field_long_integer, "m_faceA*~" },
		{ _field_legacy, _field_long_integer, "m_faceB*~" },
		{ _field_legacy, _field_long_integer, "m_userDataA*~" },
		{ _field_legacy, _field_long_integer, "m_userDataB*~" },
		{ _field_legacy, _field_short_integer, "m_costAtoB*~" },
		{ _field_legacy, _field_short_integer, "m_costBtoA*~" },
		{ _field_legacy, _field_char_integer, "m_direction*~" },
		{ _field_legacy, _field_pad, "padding", 3 },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(MobileNavMeshFlagsDefinition)
	{
		"always loaded"
	};
	STRING_LIST(MobileNavMeshFlagsDefinition, MobileNavMeshFlagsDefinition_strings, _countof(MobileNavMeshFlagsDefinition_strings));

} // namespace blofeld

