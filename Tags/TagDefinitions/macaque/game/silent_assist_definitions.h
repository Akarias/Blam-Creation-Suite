#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long SILENT_ASSIST_GLOBALS_TAG = 'slag';
	extern s_tag_group silent_assist_globals_group; // silent_assist_globals_block


	extern s_tag_block_definition silent_assist_globals_block;
	extern s_tag_block_definition silentAssistLevelBlock_block;
	extern s_tag_struct_definition silentAssistLevelBlock_block_struct_definition; // silentAssistLevelBlock_block

	extern s_tag_struct_definition silent_assist_globals_struct_definition; // tag group

	extern c_versioned_string_list g_silentAssistFlags_strings;
	extern s_string_list_definition g_silentAssistFlags;

} // namespace macaque

} // namespace blofeld

