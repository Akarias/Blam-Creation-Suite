#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long MULTILINGUAL_UNICODE_STRING_LIST_TAG = 'unic';
	extern s_tag_group multilingual_unicode_string_list_group; // multilingual_unicode_string_list_block


	extern s_tag_block_definition multilingual_unicode_string_list_block;
	extern s_tag_block_definition multilingual_unicode_string_reference_block;
	extern s_tag_struct_definition multilingual_unicode_string_reference_block_struct_definition; // multilingual_unicode_string_reference_block
	extern s_tag_block_definition string_substitution_pair_block;
	extern s_tag_struct_definition string_substitution_pair_block_struct_definition; // string_substitution_pair_block

	extern s_tag_struct_definition data_hash_definition_array_struct_definition;
	extern s_tag_array_definition data_hash_definition_array;
	extern s_tag_struct_definition multilingual_unicode_string_list_language_pack_offsets_array_struct_definition;
	extern s_tag_array_definition multilingual_unicode_string_list_language_pack_offsets_array;
	extern s_tag_struct_definition multilingual_unicode_string_list_struct_definition; // tag group
	extern s_tag_struct_definition language_pack_definition;

	extern s_tag_reference_definition global_multilingual_unicode_string_list_reference;

} // namespace macaque

} // namespace blofeld

