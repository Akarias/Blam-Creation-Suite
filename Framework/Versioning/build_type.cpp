#include "versioning-private-pch.h"

#define STRING_FILE_INFO_W L"StringFileInfo"
#define PRODUCT_NAME_W L"ProductName"
#define FILE_DESCRIPTION_W L"FileDescription"
#define HEX_LANG_ID_EN_US_W L"0409"
#define HEX_CODE_PAGE_ID_UNICODE_W L"04B0"

bool is_engine_loaded(e_engine_type engine_type)
{
	const char* engine_module_filename = get_engine_module_filename(engine_type);
	return GetModuleHandleA(engine_module_filename);
}

void* get_engine_memory_address(e_engine_type engine_type)
{
	switch (engine_type) // override for executable based engines which will always be the current module
	{
	case _engine_type_mcc:
	case _engine_type_eldorado:
		static HINSTANCE current_module = c_runtime_util::get_current_module();
		return current_module;
	}

	const char* game_executable_string = get_engine_module_filename(engine_type);
	HMODULE engine_module_handle = GetModuleHandleA(game_executable_string);
	return static_cast<void*>(engine_module_handle);
}

uint64_t get_library_file_version(const char* file_path)
{
	uint64_t result = 0;
	DWORD  version_info_handle = 0;
	DWORD  version_size = GetFileVersionInfoSizeA(file_path, &version_info_handle);

	if (version_size != NULL)
	{
		char* version_data = static_cast<char*>(alloca(version_size));

		if (GetFileVersionInfoA(file_path, NULL, version_size, version_data) != 0)
		{
			UINT version_info_size = 0;
			VS_FIXEDFILEINFO* version_info = nullptr;
			if (VerQueryValue(version_data, L"\\", (VOID FAR * FAR*)&version_info, &version_info_size))
			{
				if (version_info_size)
				{
					if (version_info->dwSignature == 0xfeef04bd)
					{
						result |= uint64_t(version_info->dwFileVersionMS);
						result <<= 32;
						result |= uint64_t(version_info->dwFileVersionLS);

					}
				}
			}
		}
	}
	return result;
}

extern uint64_t get_library_file_version(const wchar_t* file_path)
{
	DWORD  version_handle = 0;
	DWORD  version_info_size = GetFileVersionInfoSizeW(file_path, &version_handle);

	if (version_info_size != NULL)
	{
		void* version_data = alloca(version_info_size);
		if (GetFileVersionInfoW(file_path, NULL, version_info_size, version_data) != 0)
		{
			UINT   size = 0;
			LPVOID buffer = NULL;
			if (VerQueryValueW(
				version_data,
				L"\\",
				&buffer,
				&size))
			{
				if (buffer != nullptr && size > 0)
				{
					VS_FIXEDFILEINFO* file_info = static_cast<VS_FIXEDFILEINFO*>(buffer);
					if (file_info->dwSignature == 0xfeef04bd)
					{
						uint64_t result = 0;
						result |= uint64_t(file_info->dwFileVersionMS);
						result <<= 32;
						result |= uint64_t(file_info->dwFileVersionLS);
						return result;
					}
				}
			}
		}
	}

	return 0;
}

extern std::wstring get_library_description(const wchar_t* file_path)
{
	DWORD  version_handle = 0;
	DWORD  version_info_size = GetFileVersionInfoSizeW(file_path, &version_handle);

	if (version_info_size != NULL)
	{
		void* version_data = alloca(version_info_size);
		if (GetFileVersionInfoW(file_path, NULL, version_info_size, version_data) != 0)
		{
			UINT   size = 0;
			LPVOID buffer = NULL;
			if (VerQueryValueW(
				version_data, 
				L"\\" STRING_FILE_INFO_W
				L"\\" HEX_LANG_ID_EN_US_W HEX_CODE_PAGE_ID_UNICODE_W
				L"\\" FILE_DESCRIPTION_W,
				&buffer, 
				&size))
			{
				if (buffer != nullptr && size > 0)
				{
					return std::wstring(static_cast<wchar_t*>(buffer), size);
				}
			}
		}
	}

	return L"";
}

extern std::wstring get_library_product_name(const wchar_t* file_path)
{
	DWORD  version_handle = 0;
	DWORD  version_info_size = GetFileVersionInfoSizeW(file_path, &version_handle);

	if (version_info_size != NULL)
	{
		void* version_data = alloca(version_info_size);
		if (GetFileVersionInfoW(file_path, NULL, version_info_size, version_data) != 0)
		{
			UINT   size = 0;
			LPVOID buffer = NULL;
			if (VerQueryValueW(
				version_data,
				L"\\" STRING_FILE_INFO_W
				L"\\" HEX_LANG_ID_EN_US_W HEX_CODE_PAGE_ID_UNICODE_W
				L"\\" PRODUCT_NAME_W,
				&buffer,
				&size))
			{
				if (buffer != nullptr && size > 0)
				{
					return std::wstring(static_cast<wchar_t*>(buffer), size);
				}
			}
		}
	}

	return L"";
}

uintptr_t get_engine_base_address(e_engine_type engine_type)
{
	static e_engine_type engine_type_prev = _engine_type_not_set;
	static uintptr_t result = ~uintptr_t();

	if (engine_type != engine_type_prev)
	{
		WCHAR Path[MAX_PATH + 1];
		DWORD dwRet = GetModuleFileName(GetModuleHandleA(get_engine_module_filename(engine_type)), Path, MAX_PATH);

		HANDLE file = CreateFile(Path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (file != INVALID_HANDLE_VALUE)
		{
			HANDLE file_mapping = CreateFileMapping(file, NULL, PAGE_READONLY, 0, 0, NULL);
			if (file_mapping != 0)
			{
				LPVOID file_base_address = MapViewOfFile(file_mapping, FILE_MAP_READ, 0, 0, 0);
				if (file_base_address != 0)
				{
					PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)file_base_address;
					if (dos_header->e_magic == IMAGE_DOS_SIGNATURE)
					{
						PIMAGE_NT_HEADERS nt_header = (PIMAGE_NT_HEADERS)((UINT64)dos_header + (UINT64)dos_header->e_lfanew);
						result = nt_header->OptionalHeader.ImageBase;
					}
					UnmapViewOfFile(file_base_address);
				}
				CloseHandle(file_mapping);
			}
			CloseHandle(file);
		}

		engine_type_prev = engine_type;
	}

	return result;
}

uintptr_t get_engine_top_address(e_engine_type engine_type, e_build build)
{
	static e_engine_type engine_type_prev = _engine_type_not_set;
	static uintptr_t result = ~uintptr_t();

	if (engine_type != engine_type_prev)
	{
		WCHAR Path[MAX_PATH + 1];
		DWORD dwRet = GetModuleFileName(GetModuleHandleA(get_engine_module_filename(engine_type)), Path, MAX_PATH);

		HANDLE file = CreateFile(Path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (file != INVALID_HANDLE_VALUE)
		{
			HANDLE file_mapping = CreateFileMapping(file, NULL, PAGE_READONLY, 0, 0, NULL);
			if (file_mapping != 0)
			{
				LPVOID file_base_address = MapViewOfFile(file_mapping, FILE_MAP_READ, 0, 0, 0);
				if (file_base_address != 0)
				{
					PIMAGE_DOS_HEADER dos_header = (PIMAGE_DOS_HEADER)file_base_address;
					if (dos_header->e_magic == IMAGE_DOS_SIGNATURE)
					{
						PIMAGE_NT_HEADERS nt_header = (PIMAGE_NT_HEADERS)((UINT64)dos_header + (UINT64)dos_header->e_lfanew);
						result = nt_header->OptionalHeader.ImageBase + nt_header->OptionalHeader.SizeOfImage;
					}
					UnmapViewOfFile(file_base_address);
				}
				CloseHandle(file_mapping);
			}
			CloseHandle(file);
		}

		engine_type_prev = engine_type;
	}

	return result;
}