
size_t halo3_spawn_ai_with_scripts_and_effects_patch_size(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 2);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 6);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 6);
	return ~size_t();
}
uintptr_t halo3_spawn_ai_with_scripts_and_effects_patch_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo3, _build_mcc_1_1629_0_0, 0x18063445E);
	OFFSET(_engine_type_halo3, _build_mcc_1_1698_0_0, 0x18064014E);
	OFFSET(_engine_type_halo3, _build_mcc_1_1716_0_0, 0x18064014E);
	OFFSET(_engine_type_halo3, _build_mcc_1_1767_0_0, 0x1801B8D30);
	OFFSET(_engine_type_halo3, _build_mcc_1_1778_0_0, 0x1801B8DC0);
	OFFSET(_engine_type_halo3, _build_mcc_1_1792_0_0, 0x1801B9290);
	OFFSET(_engine_type_halo3, _build_mcc_1_1829_0_0, 0x1801BDF10);
	OFFSET(_engine_type_halo3, _build_mcc_1_1864_0_0, 0x1801BDF10);
	OFFSET(_engine_type_halo3, _build_mcc_1_1871_0_0, 0x1801BDF10);
	OFFSET(_engine_type_halo3, _build_mcc_1_1955_0_0, 0x18055D4A3);
	OFFSET(_engine_type_halo3, _build_mcc_1_2028_0_0, 0x180560ACB);
	return ~uintptr_t();
}
// Allows spawning AI via scripts or effects, props to Exhibit
c_data_patch<halo3_spawn_ai_with_scripts_and_effects_patch_offset> halo3_spawn_ai_with_scripts_and_effects_patch = {
[](e_engine_type engine_type, e_build build, char* data, DataPatchPacket& packet)
{
	size_t patch_size = halo3_spawn_ai_with_scripts_and_effects_patch_size(engine_type, build);
	if (patch_size != ~size_t())
	{
		packet = MAKE_DATAPATCHPACKET(data, patch_size);
		nop_address(data, patch_size);
	}
} };