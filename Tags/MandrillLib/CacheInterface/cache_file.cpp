#include "mandrilllib-private-pch.h"

uint64_t _convert_page_offset(uint32_t page_offset, uint32_t page_address_offset, uint64_t virtual_base_address)
{
	uint64_t virtual_address = static_cast<uint64_t>(page_offset) * 4ull + page_address_offset;
	uint64_t relative_virtual_address = virtual_address - virtual_base_address;
	return relative_virtual_address;
}

bool is_page_offset_with_map_valid(char* map_data, uint32_t page_address_offset) // use for determining between halo4/groundhog
{
	halo4::s_cache_file_header& cache_file_header = *reinterpret_cast<halo4::s_cache_file_header*>(map_data);
	if (cache_file_header.file_version != 12)
	{
		return false;
	}

	s_section_cache tags_section; // #TODO: Write a function for this
	{
		gen3::e_cache_file_section_index cache_file_section_index = gen3::_cache_file_section_index_tags;

		long mask = cache_file_header.section_table.offset_masks[cache_file_section_index];
		long offset = cache_file_header.section_table.sections[cache_file_section_index].offset;
		long size = cache_file_header.section_table.sections[cache_file_section_index].size;

		char* masked_data = reinterpret_cast<char*>(map_data + mask);
		char* data = masked_data + offset;

		tags_section.mask = mask;
		tags_section.offset = offset;
		tags_section.size = size;
		tags_section.masked_data = masked_data;
		tags_section.data = data;
	}

	char* tags_buffer = tags_section.masked_data + cache_file_header.tag_buffer_offset;

	halo4::s_cache_file_tags_header& tags_header = *reinterpret_cast<halo4::s_cache_file_tags_header*>(tags_buffer + (cache_file_header.tags_header_address - cache_file_header.virtual_base_address));
	gen3::s_cache_file_tag_instance* tag_instances = reinterpret_cast<gen3::s_cache_file_tag_instance*>(tags_buffer + (tags_header.tag_instances.address - cache_file_header.virtual_base_address));

	uint32_t page_offset_to_first_tag = tag_instances[0].address;
	uint64_t bytes_to_first_tag = _convert_page_offset(page_offset_to_first_tag, page_address_offset, cache_file_header.virtual_base_address);

	bool is_valid = bytes_to_first_tag < cache_file_header.tag_buffer_size;

	return is_valid;
}

e_engine_type c_cache_file::get_cache_file_engine_type(const wchar_t* filepath, long* file_version)
{
	FILE* file_handle = _wfopen(filepath, L"rb");
	if (file_handle == nullptr)
	{
		return _engine_type_not_set;
	}

	_fseeki64(file_handle, 0, SEEK_SET);

	blamlib::s_cache_file_header header;
	if (!filesystem_read_from_file_handle(file_handle, &header, sizeof(header)))
	{
		return _engine_type_not_set; // likely an empty file
	}

	e_engine_type engine_type = _engine_type_not_set;
	if (header.header_signature == 'head' || header.header_signature == 'daeh')
	{
		uint32_t footer_search_value;
		do
		{
			if (!filesystem_read_from_file_handle(file_handle, &footer_search_value, sizeof(footer_search_value)))
			{
				return _engine_type_not_set; // likely an empty file
			}
		} while (footer_search_value != 'foot' && footer_search_value != 'toof');

		long long header_size = _ftelli64(file_handle);

		const long long  k_haloreach_header_memory_footprint = 0xA000;
		const long long  k_halo2_header_memory_footprint = 0x1000;
		const long long  k_halo3_header_memory_footprint = 0x3000;
		const long long  k_halo3odst_header_memory_footprint = 0x2FFC;
		const long long  k_halo4_and_groundhog_header_memory_footprint = 0x1E000;

		switch (header_size)
		{
		case k_haloreach_header_memory_footprint:
			c_console::write_line_verbose("cache file type halo reach");
			engine_type = _engine_type_haloreach;
			break;
		case k_halo2_header_memory_footprint:
			c_console::write_line_verbose("cache file type halo 2");
			engine_type = _engine_type_halo2;
			break;
		case k_halo3_header_memory_footprint:
			c_console::write_line_verbose("cache file type halo 3");
			engine_type = _engine_type_halo3;
			break;
		case k_halo3odst_header_memory_footprint:
			c_console::write_line_verbose("cache file type halo 3 odst");
			engine_type = _engine_type_halo3odst;
			break;
		case k_halo4_and_groundhog_header_memory_footprint:
		{
			char* map_data = nullptr; // #TODO: use memory mapped file
			_fseeki64(file_handle, 0, SEEK_SET);
			if (!filesystem_read_from_file_handle_to_memory(file_handle, (void**)&map_data))
			{
				return _engine_type_not_set; // likely an empty file
			}

			if (is_page_offset_with_map_valid(map_data, c_halo4_cache_file::page_address_offset))
			{
				DEBUG_ASSERT(engine_type == _engine_type_not_set);
				c_console::write_line_verbose("cache file type halo 4");
				engine_type = _engine_type_halo4;
			}
			else if (is_page_offset_with_map_valid(map_data, c_groundhog_cache_file::page_address_offset))
			{
				c_console::write_line_verbose("cache file type groundhog");
				engine_type = _engine_type_groundhog;
			}
			else
			{
				c_console::write_line_verbose("unknown halo 4/groundhog cache file version");
			}

			delete[] map_data;
			break;
		}
		default:
			DEBUG_FATAL_ERROR(L"Unknown map type");
		}

		*file_version = header.file_version;
	}
	else
	{
		*file_version = -1;
		// #TODO: Attempt to identify as a Halo 1 file format
		if (wcscmp_ic(filepath, L".map") == 0)
		{
			engine_type = _engine_type_halo1;
		}
	}

	fclose(file_handle);

	return engine_type;
}

c_cache_file* c_cache_file::create_cache_file(const std::wstring& map_filepath, c_cache_cluster* cache_cluster)
{
	for (c_mandrill_extension& extension : c_reference_loop(c_mandrill_extension::get_extensions(), c_mandrill_extension::get_extension_count()))
	{
		c_cache_file* cache_file = extension.create_cache_file(map_filepath);
		if (cache_file)
		{
			return cache_file;
		}
	}

	long file_version = ~long();
	e_engine_type engine_type = get_cache_file_engine_type(map_filepath.c_str(), &file_version);
	switch (engine_type)
	{
	case _engine_type_haloreach:
		return new c_haloreach_cache_file(map_filepath, cache_cluster);
	case _engine_type_halo1:
		return new c_halo1_cache_file(map_filepath);
	case _engine_type_halo2:
		return new c_halo2_cache_file(map_filepath);
	case _engine_type_halo3:
		return new c_halo3_cache_file(map_filepath);
	case _engine_type_halo3odst:
		return new c_halo3odst_cache_file(map_filepath);
	case _engine_type_halo4:
		return new c_halo4_cache_file(map_filepath);
	case _engine_type_groundhog:
		return new c_groundhog_cache_file(map_filepath);

	}

	return nullptr;
}

c_cache_file::c_cache_file(const std::wstring& map_filepath, e_engine_type engine_type, e_platform_type platform_type) :
	virtual_memory_container(*new c_virtual_memory_container(2ull * 1024ull * 1024ull * 1024ull)),
	map_filepath(map_filepath.c_str()),
	engine_type(engine_type),
	platform_type(platform_type)
{
	map_filename = PathFindFileNameW(map_filepath.c_str());

	char buffer[MAX_PATH + 1];

	snprintf(buffer, MAX_PATH, "%S", map_filename.c_str());
	buffer[MAX_PATH] = 0;
	map_filename_utf8 = buffer;

	snprintf(buffer, MAX_PATH, "%S", map_filepath.c_str());
	buffer[MAX_PATH] = 0;
	map_filepath_utf8 = buffer;
}

c_cache_file::~c_cache_file()
{
	delete& virtual_memory_container;
}

char* c_cache_file::get_map_data()
{
	char* map_data = virtual_memory_container.get_data();
	return map_data;
}

uint64_t c_cache_file::convert_virtual_address(uint64_t virtual_address) const
{
	return virtual_address - get_base_virtual_address();
}

c_tag_interface* c_cache_file::get_tag_interface(uint32_t tag_index) const
{
	if (tag_index < get_tag_count())
	{
		return tag_interfaces[tag_index];
	}
	return nullptr;
}

c_tag_interface* const* c_cache_file::get_tag_interfaces() const
{
	if (get_tag_count() > 0)
	{
		return tag_interfaces.data();
	}
	return nullptr;
}

c_tag_interface* const* c_cache_file::get_tag_interfaces_sorted_by_name_with_group_id() const
{
	if (get_tag_count() > 0)
	{
		return tag_interfaces.data();
	}
	if (get_tag_count() > 0)
	{
		return tag_interfaces_sorted_by_name_with_group_id.data();
	}
	return nullptr;
}

c_tag_interface* const* c_cache_file::get_tag_interfaces_sorted_by_path_with_group_id() const
{
	if (get_tag_count() > 0)
	{
		return tag_interfaces.data();
	}
	if (get_tag_count() > 0)
	{
		return tag_interfaces_sorted_by_path_with_group_id.data();
	}
	return nullptr;
}

c_tag_interface* const* c_cache_file::get_tag_interfaces_sorted_by_data_address() const
{
	if (get_tag_count() > 0)
	{
		return tag_interfaces.data();
	}
	if (get_tag_count() > 0)
	{
		return tag_interfaces_sorted_by_data_address.data();
	}
	return nullptr;
}

c_tag_group_interface* c_cache_file::get_tag_group_interface(uint16_t group_index) const
{
	if (group_index < get_tag_group_count())
	{
		return tag_group_interfaces[group_index];
	}
	return nullptr;
}

c_tag_group_interface* c_cache_file::get_tag_group_interface_by_group_id(unsigned long tag_group) const
{
	if (tag_group == blofeld::INVALID_TAG)
	{
		return nullptr;
	}

	for (c_tag_group_interface* group_interface : tag_group_interfaces)
	{
		if (group_interface->get_group_tag() == tag_group)
		{
			return group_interface;
		}
	}
	return nullptr;
}

c_tag_group_interface* const* c_cache_file::get_tag_group_interfaces() const
{
	if (get_tag_group_count() > 0)
	{
		return tag_group_interfaces.data();
	}
	return nullptr;
}

void c_cache_file::set_cache_cluster(c_cache_cluster* cluster)
{

}

#pragma optimize( "t", on ) // always prefer fast code here

static bool sort_tag_instance_by_name_with_group_id(c_tag_interface* left_tag_interface, c_tag_interface* right_tag_interface)
{
	if (left_tag_interface->is_null()) return true;
	if (right_tag_interface->is_null()) return false;

	const char* left_begin = left_tag_interface->get_name_with_group_id_cstr();
	const char* right_begin = right_tag_interface->get_name_with_group_id_cstr();
	const char* left_end = left_begin + strlen(left_begin) + 1;
	const char* right_end = right_begin + strlen(right_begin) + 1;
	return std::lexicographical_compare(left_begin, left_end, right_begin, right_end, [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}

static bool sort_tag_instance_by_path_with_group_id(c_tag_interface* left_tag_interface, c_tag_interface* right_tag_interface)
{
	if (left_tag_interface->is_null()) return true;
	if (right_tag_interface->is_null()) return false;

	const char* left_begin = left_tag_interface->get_name_with_group_id_cstr();
	const char* right_begin = right_tag_interface->get_name_with_group_id_cstr();
	const char* left_end = left_begin + strlen(left_begin) + 1;
	const char* right_end = right_begin + strlen(right_begin) + 1;
	return std::lexicographical_compare(left_begin, left_end, right_begin, right_end, [](char x, char y) { return toupper(static_cast<unsigned char>(x)) < toupper(static_cast<unsigned char>(y)); });
}

static bool sort_tag_instance_by_data_address(c_tag_interface* left_tag_interface, c_tag_interface* right_tag_interface)
{
	return left_tag_interface->get_data() < right_tag_interface->get_data();
}

#pragma optimize( "", on ) // restore global optimization settings

void c_cache_file::init_sorted_instance_lists()
{
	c_tag_group_interface** group_interfaces_buffer = tag_group_interfaces.data();
	std::function create_group = [this, group_interfaces_buffer](uint32_t index)
	{
		c_tag_group_interface* group_interface = group_interfaces_buffer[index];
		group_interface->init_sorted_instance_lists();
	};
	tbb::parallel_for(0u, static_cast<uint32_t>(tag_group_interfaces.size()), create_group);

	//tag_interfaces_sorted_by_name_with_group_id.resize(tag_interfaces.size());
	//std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_name_with_group_id.begin(), tag_interfaces_sorted_by_name_with_group_id.end(), sort_tag_instance_by_name_with_group_id);
	tag_interfaces_sorted_by_name_with_group_id = tag_interfaces;

	//tag_interfaces_sorted_by_path_with_group_id.resize(tag_interfaces.size());
	//std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_path_with_group_id.begin(), tag_interfaces_sorted_by_path_with_group_id.end(), sort_tag_instance_by_path_with_group_id);
	tag_interfaces_sorted_by_path_with_group_id = tag_interfaces;

	//tag_interfaces_sorted_by_data_address.resize(tag_interfaces.size());
	//std::partial_sort_copy(tag_interfaces.begin(), tag_interfaces.end(), tag_interfaces_sorted_by_data_address.begin(), tag_interfaces_sorted_by_data_address.end(), sort_tag_instance_by_data_address);
	tag_interfaces_sorted_by_data_address = tag_interfaces;
}
