#pragma once
class c_game_runtime
{
public:
	c_game_runtime(e_engine_type engine_type, const char* pEngineName, const char* pLibFileName, bool useExistingLoadedModule = false, e_build build = _build_not_set);
	~c_game_runtime();

	IDataAccess* GetDataAccess() const { return m_pDataAccess; };
	e_build get_build() const { return m_build; }

	inline __int64 __fastcall CreateDataAccess(IDataAccess** ppDataAccess)
	{
		ASSERT(pCreateDataAccess != nullptr);
		__IDataAccess* data_access = nullptr;
		__int64 result = pCreateDataAccess(&data_access);
		*ppDataAccess = nullptr;
		if (data_access)
		{
			*ppDataAccess = new IDataAccess(*data_access, get_build());
		}
		return result;
	}

	inline signed __int64 __fastcall CreateGameEngine(IGameEngine** ppGameEngine)
	{
		ASSERT(pCreateDataAccess != nullptr);
		__IGameEngine* game_engine = nullptr;
		__int64 result = pCreateGameEngine(&game_engine);
		*ppGameEngine = nullptr;
		if (game_engine)
		{
			*ppGameEngine = new IGameEngine(*game_engine, get_build());
		}
		return result;
	}

	inline errno_t __fastcall SetLibrarySettings(wchar_t* Src)
	{
		ASSERT(pSetLibrarySettings != nullptr);
		return pSetLibrarySettings(Src);
	}

	inline std::string GetEngineName()
	{
		return m_engineName;
	}

	static e_build get_library_file_version(const char* file_path);
private:
	void loadLibrary(const char* pLibFileName);

	std::string m_engineName;
	LPCSTR m_enginePath = "";
	e_build m_build = _build_not_set;
	IDataAccess* m_pDataAccess = nullptr;
	HMODULE hGameModule = NULL;

	typedef __int64(__fastcall CreateDataAccessFunc)(__IDataAccess** ppDataAccess);
	CreateDataAccessFunc* pCreateDataAccess = nullptr;

	typedef signed __int64(__fastcall CreateGameEngineFunc)(__IGameEngine** ppGameEngine);
	CreateGameEngineFunc* pCreateGameEngine = nullptr;

	typedef errno_t(__fastcall SetLibrarySettingsFunc)(wchar_t* Src);
	SetLibrarySettingsFunc* pSetLibrarySettings = nullptr;
};
