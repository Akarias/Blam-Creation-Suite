#pragma once

enum e_platform_type : uint8_t
{
	_platform_type_not_set,
	_platform_type_xbox,
	_platform_type_xbox_360,
	_platform_type_xbox_one,
	_platform_type_pc,
	_platform_type_pc_legacy,
	k_number_of_platform_types
};

template<typename string_type, bool pretty_string>
inline string_type get_enum_string(e_platform_type platform_type)
{
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_not_set, "Not Set");
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_xbox, "Xbox");
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_xbox_360, "Xbox 360");
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_xbox_one, "Xbox One");
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_pc, "PC");
	enum_string_ex(string_type, pretty_string, platform_type, _platform_type_pc_legacy, "PC (Legacy)");
	return nullptr;
}

inline uint32_t get_platform_pointer_size(e_platform_type platform_type)
{
	switch (platform_type)
	{
	case _platform_type_xbox:
	case _platform_type_pc_legacy:
	case _platform_type_xbox_360:
		return 4;
	case _platform_type_xbox_one:
	case _platform_type_pc:
		return 8;
	case _platform_type_not_set:
	default: throw;
		break;
	}
}
