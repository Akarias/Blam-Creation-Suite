#pragma once

class c_blamlib_string_parser
{
public:
	c_blamlib_string_parser(const char* name, bool is_block = 0, std::map<std::string, int>* field_name_unique_counter = nullptr);
	void cleanup_code_name();

	c_fixed_string_2048 string;
	c_fixed_string_512 display_name;
	c_fixed_string_512 alt_name;
	c_fixed_string_128 units;
	c_fixed_string_2048 description;
	c_fixed_string_128 minimum;
	c_fixed_string_128 maximum;
	bool read_only;
	bool is_index;
	bool is_pointer;

	c_fixed_string_512 code_name;

	static std::pair<const char*, const char*> bespoke_fixups[];
};

