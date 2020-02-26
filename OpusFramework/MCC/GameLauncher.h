#pragma once

class GameLauncher
{
public:
	static void Init();
	static void Deinit();
	static void OpusTick();
	static void WindowDestroyCallback();
	inline static bool IsGameRunning() { return s_gameRunning; }
private:
	static void loadSettings();
	static void update();
	static void renderMainMenu();
	static void renderUI();
	static void gameRender();
	static void launchGame(Engine engine);
	static void checkSteamOwnership();
	static void entireLibraryIsLoaded(const char* pLibName, const char* pFallbackDir);
	static void renderPauseMenu();

	// #TODO: Move these into each lib
#ifdef _WIN64
	static void launchHalo1();
	static void launchHaloReach();
#else
	static void launchEldorado();
#endif
private:

public:
	using GenericGameEvent = void(*)(Engine engine, Build build);
	inline static void RegisterGameStartupCallback(GenericGameEvent eventCallback) { s_gameStartupEvent.push_back(eventCallback); }
	inline static void RegisterGameShutdownCallback(GenericGameEvent eventCallback) { s_gameShutdownEvent.push_back(eventCallback); }
	inline static void UnregisterGameLaunchCallback(GenericGameEvent eventCallback) { VectorEraseByValueHelper(s_gameStartupEvent, eventCallback); }
	inline static void UnregisterGameShutdownCallback(GenericGameEvent eventCallback) { VectorEraseByValueHelper(s_gameShutdownEvent, eventCallback); }
private:
	static std::vector<GenericGameEvent> s_gameStartupEvent;
	static std::vector<GenericGameEvent> s_gameShutdownEvent;
	static bool s_gameRunning;
};

//class LegacyGameLauncher
//{
//public:
//	enum class CurrentState
//	{
//		eInactive,
//		eMainMenu,
//		eWaitingToRun,
//		eRunning,
//		eFinished
//	};
//
//	enum class SelectedGameModeMapInfoIndex
//	{
//		Campaign,
//		Multiplayer,
//		Firefight,
//		Unknown,
//		Count
//	};
//
//	typedef void(GameLaunchCallback)(EngineVersion engine, BuildVersion build);
//	typedef void(GameShutdownCallback)(EngineVersion engine, BuildVersion build);
//
//	static void Init(HINSTANCE hInstance, LPSTR lpCmdLine);
//	static void Deinit();
//	static void RegisterTerminationValue(char& rTerminationReference);
//
//	
//	static void Terminate();
//	static void EnsureBink2Win64IsLoaded(const char* pLibName, const char* pFallbackDir = "");
//	static void RegisterGameLaunchCallback(EngineVersion engine, GameLaunchCallback gameLaunchCallback);
//	static void RegisterGameShutdownCallback(EngineVersion engine, GameShutdownCallback gameShutdownCallback);
//	static void LoadSettings();
//	static int Run(HINSTANCE hInstance, LPSTR lpCmdLine, GameRuntime& rGameRuntime);
//	static void SetupGameContext(GameContext& gameContext);
//	static void LaunchGame();
//	static void SetState(CurrentState state);
//	static void Update();
//	static void Render();
//	static void BeginRender();
//	static void EndRender();
//	static void DrawMainMenu();
//	static void DrawPauseMenu();
//
//	static const MapInfo* GetDefaultHaloReachGameOptionSelection(SelectedGameModeMapInfoIndex gameModeMapInfoIndex);
//	static void SelectGameMode();
//	static bool IsMapInfoCompatibleWithGameMode(GameMode gameMode, const MapInfo& rMapInfo);
//	static const MapInfo* GetFirstSuitableGameModeMapInfo(GameMode gameMode);
//	static void SaveSelectedMap(GameMode gameMode, const MapInfo* pMapInfo);
//	static SelectedGameModeMapInfoIndex GameModeToSelectedGameModeMapInfoIndex(GameMode gameMode);
//	static GameMode SelectedGameModeMapInfoIndexToGameMode(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);
//	static const MapInfo*& GetSelectedMapInfoBySelectedGameModeMapInfoIndex(SelectedGameModeMapInfoIndex selectedGameModeMapInfoIndex);
//	static const MapInfo*& GetSelectedMapInfoByGameMode(GameMode gameMode);
//	static void SelectMap();
//	static void SelectDifficulty();
//	static void SelectGameVariant();
//	static void SelectMapVariant();
//	static void SelectSavedFilm();
//
//
//	static void CheckSteamAPI();
//
//
//	static char* s_pTerminationFlag;
//	BuildVersion GetCurrentbuild();
//	static bool s_gameManuallyKilled;
//	static bool s_hideWindowOnStartup; 
//
//	static CurrentState s_currentState;
//	// #TODO: Implement a map and vector for this!!!
//	static GameLaunchCallback* s_gameLaunchCallback;
//	static GameShutdownCallback* s_gameShutdownCallback;
//	static GameRuntime* s_pCurrentGameRuntime;
//	static IGameEngine* s_pHaloReachEngine;
//	static std::atomic<int> s_uiStackLength;
//
//	static const MapInfo* s_pSelectedMapInfo[underlying_cast(SelectedGameModeMapInfoIndex::Count)];
//	static constexpr const char* s_kpMapInfoSettingsName[underlying_cast(SelectedGameModeMapInfoIndex::Count)] = { "LastCampaignMap", "LastMultiplayerMap", "LastSurvivalMap", "LastUnknownGamemodeMap" };
//};

