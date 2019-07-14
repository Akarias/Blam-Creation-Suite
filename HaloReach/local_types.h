#pragma once


/*
   This file has been generated by IDA.
   It contains local type definitions from
   the type library 'MCC-Win64-Shipping.exe'
*/

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

struct _RTL_CRITICAL_SECTION_DEBUG;
struct IGameEngine;
struct GameEvents_vftbl;
struct GameEvents;
struct GameEngineHostCallback_vftbl;
struct GameEngineHostCallback;

typedef void(NullSubFunc)();

/* 514 */
struct __declspec(align(8)) IGameEngine_vftbl
{
	void(__fastcall* InitGraphics)(IGameEngine*, __int64, __int64, __int64, __int64);
	void(__fastcall* InitThread)(IGameEngine*, GameEngineHostCallback*, __int64);
	void* Member02;
	void* Member03;
	void* Member04;
	void* Member05;
	void* Member06;
	void* Member07;
	void* Member08;
	void* Member09;
	void* Member10;
};

/* 17 */
//typedef unsigned int DWORD;

/* 515 */
struct IGameEngine
{
	IGameEngine_vftbl* vftbl;
	DWORD unknown0;
	float unknown1;
	char unknown2[454];

	void InitGraphics(__int64 a1, __int64 a2, __int64 /*IDXGISwapChain **/pSwapChain, __int64 a4)
	{
		vftbl->InitGraphics(this, a1, a2, pSwapChain, a4);
	}
	void InitThread(GameEngineHostCallback* gameEngineHostCallback, __int64 a2)
	{
		vftbl->InitThread(this, gameEngineHostCallback, a2);
	}
};

/* 516 */
struct GameEngineHostCallback_vftbl
{
	NullSubFunc* Member00;
	NullSubFunc* Member01;
	NullSubFunc* Member02;
	NullSubFunc* Member03;
	NullSubFunc* Member04;
	void(__fastcall* WriteGameState)(GameEngineHostCallback*, LPVOID, size_t);
	NullSubFunc* Member06;
	NullSubFunc* Member07;
	NullSubFunc* Member08;
	NullSubFunc* Member09;
	NullSubFunc* Member10;
	NullSubFunc* Member11; // DataAccessGameVariant
	NullSubFunc* Member12; // DataAccessMapVariant
	NullSubFunc* Member13;
	NullSubFunc* Member14;
	NullSubFunc* Member15;
	NullSubFunc* Member16;
	NullSubFunc* Member17;
	NullSubFunc* Member18;
	NullSubFunc* Member19;
	NullSubFunc* Member20;
	NullSubFunc* Member21;
	NullSubFunc* Member22;
	NullSubFunc* Member23;
	NullSubFunc* Member24;
	NullSubFunc* Member25;
	NullSubFunc* Member26;
	NullSubFunc* Member27;
	NullSubFunc* Member28;
	NullSubFunc* Member29;
	NullSubFunc* Member30;
	NullSubFunc* Member31;
	NullSubFunc* Member32;
	NullSubFunc* Member33;
	NullSubFunc* Member34;
	NullSubFunc* Member35;
	NullSubFunc* Member36;
	NullSubFunc* Member37;
	NullSubFunc* Member38;
	NullSubFunc* Member39;
	NullSubFunc* Member40;
	NullSubFunc* Member41;
	NullSubFunc* Member42;
};

/* 517 */
struct __declspec(align(8)) GameEngineHostCallback
{
	GameEngineHostCallback_vftbl* vftbl;
	GameEvents* pGameEvents;
	QWORD data1[5863];
};


/* 4 */
typedef struct _GUID GUID;

/* 23 */
typedef _RTL_CRITICAL_SECTION_DEBUG* PRTL_CRITICAL_SECTION_DEBUG;


/* 28 */
typedef void* HANDLE;

/* 29 */
typedef unsigned __int64 ULONG_PTR;


/* 520 */
struct __declspec(align(8)) UnknownType0
{
	QWORD qword0;
	QWORD* qword1;
	QWORD* qword2;
	DWORD dword0;
	DWORD dword1;
	QWORD qword4;
	QWORD* qword5;
	QWORD* qword6;
	DWORD dword2;
	DWORD dword3;
	DWORD dword4;
	DWORD dword5;
};

/* 519 */
struct GameEvents
{
	GameEvents_vftbl* vftbl;
	_WORD word0;
	_WORD word1;
	GUID guid;
	__unaligned __declspec(align(1)) _QWORD qword0;
	__unaligned __declspec(align(1)) _QWORD qword1;
	__unaligned __declspec(align(1)) _QWORD qword2;
	__unaligned __declspec(align(1)) _QWORD qword3;
	__unaligned __declspec(align(1)) _QWORD qword4;
	__unaligned __declspec(align(1)) _QWORD qword5;
	__unaligned __declspec(align(1)) _QWORD qword6;
	__unaligned __declspec(align(1)) _QWORD qword7;
	_DWORD dword0;
	_DWORD dword1;
	_DWORD dword2;
	_RTL_CRITICAL_SECTION rtlCriticalSection;
	_QWORD qword8;
	UnknownType0 unknownStruct;
	_QWORD qword9;
	_QWORD qwordA;
	_QWORD qwordB;
};

/* 518 */
struct __declspec(align(8)) GameEvents_vftbl
{
	NullSubFunc* Member00;
	NullSubFunc* AshesToAshes;
	NullSubFunc* Assist;
	NullSubFunc* AudioLogClaimed;
	NullSubFunc* Base;
	NullSubFunc* Betrayal;
	__int64(__fastcall* BIFactControllerSettings)(GameEvents*, unsigned __int64*, GUID*, _QWORD, __int64, _DWORD, int, int);
	NullSubFunc* BIFactDeepLinkRecieve;
	void(__fastcall* BIFactDeepLinkSend)(GameEvents*, _QWORD*, GUID*, _QWORD*, __int64*);
	NullSubFunc* BIFactDualWield;
	NullSubFunc* BIFactGameSession;
	NullSubFunc* BIFactLoadout;
	NullSubFunc* BIFactMatchmaking;
	NullSubFunc* BIFactMatchmakingDetails;
	NullSubFunc* BIFactMedia;
	NullSubFunc* BirdOfPrey;
	NullSubFunc* BitsAndPiecesDestroyed;
	NullSubFunc* BroadcastingAssist;
	NullSubFunc* BroadcastingDeath;
	NullSubFunc* BroadcastingHeartbeat;
	NullSubFunc* BroadcastingKill;
	NullSubFunc* BroadcastingMatchEnd;
	NullSubFunc* MultiplayerRoundEnd;
	NullSubFunc* MultiplayerRoundStart;
	NullSubFunc* BroadcastingMatchStart;
	NullSubFunc* BroadcastingMedal;
	NullSubFunc* BroadcastingPlayerJoined;
	NullSubFunc* BroadcastingPlayerLeft;
	NullSubFunc* BroadcastingPlayerSpawn;
	NullSubFunc* BroadcastingPlayerSwitchedTeams;
	NullSubFunc* BroadcastingScore;
	void(__fastcall* BroadcastingStart)(GameEvents*, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD);
	NullSubFunc* ChallengeCompleted;
	NullSubFunc* ClassicModeSwitched;
	NullSubFunc* CleverGirl;
	NullSubFunc* ClueClaimed;
	NullSubFunc* CompletionCount;
	NullSubFunc* Customization;
	NullSubFunc* DashboardContext;
	NullSubFunc* Death;
	NullSubFunc* DollFound;
	NullSubFunc* EliteWin;
	NullSubFunc* EnemyDefeated;
	NullSubFunc* FriendsBestedOnHeroLeaderboard;
	NullSubFunc* GameProgress;
	NullSubFunc* GameVarSaved;
	NullSubFunc* HelloNurse;
	NullSubFunc* InGamePresence;
	NullSubFunc* ISeeYou;
	NullSubFunc* Joinability;
	NullSubFunc* Lobby;
	NullSubFunc* MainMenuPresence;
	NullSubFunc* MapVarSaved;
	NullSubFunc* MatchmakingHopper;
	NullSubFunc* MediaUsage;
	NullSubFunc* MeldOfferPresented;
	NullSubFunc* MeldOfferResponded;
	NullSubFunc* MeldPageAction;
	NullSubFunc* MeldPageView;
	NullSubFunc* MissionCompleted;
	NullSubFunc* MortardomWraithsKilled;
	NullSubFunc* MultiplayerGameEngine;
	NullSubFunc* MultiplayerRoundEnd_0;
	NullSubFunc* MultiplayerRoundStart_0;
	NullSubFunc* NappersCaught;
	NullSubFunc* NewsStoryRead;
	NullSubFunc* ObjectiveEnd;
	NullSubFunc* ObjectiveStart;
	NullSubFunc* PageAction;
	NullSubFunc* PageView;
	NullSubFunc* PhantomHunter;
	NullSubFunc* PigsCanFly;
	NullSubFunc* PlayerCheckedInToday;
	NullSubFunc* PlayerDefeated;
	NullSubFunc* PlayerGameResults;
	NullSubFunc* PlayerGameResultsDamageStat;
	NullSubFunc* PlayerGameResultsGriefingStats;
	NullSubFunc* PlayerGameResultsInterestStats;
	NullSubFunc* PlayerGameResultsMedal;
	NullSubFunc* PlayerSessionEnd;
	NullSubFunc* PlayerSessionPause;
	NullSubFunc* PlayerSessionResume;
	NullSubFunc* PlayerSessionStart;
	NullSubFunc* PlayerSpawned;
	NullSubFunc* PlaylistCompleted;
	NullSubFunc* PlaylistProgress;
	NullSubFunc* RankedStatsDNFInfo;
	NullSubFunc* RankedStatsOverride;
	NullSubFunc* RankedStatsPenalty;
	NullSubFunc* RankedStatsUpdate;
	NullSubFunc* RankedUpSpartanIv;
	NullSubFunc* RealtimeFlagCaptured;
	NullSubFunc* RealtimeMedal;
	NullSubFunc* RealtimePilotedVehicle;
	NullSubFunc* RivalID;
	NullSubFunc* SectionEnd;
	NullSubFunc* SectionStart;
	NullSubFunc* SectionStats;
	NullSubFunc* SessionSizeUpdate;
	NullSubFunc* SizeIsEverything;
	NullSubFunc* SkeetShooter;
	NullSubFunc* SkullClaimed;
	NullSubFunc* SpartanOpsMissionCompleted;
	NullSubFunc* TerminalFound;
	NullSubFunc* TicketsEarned;
	NullSubFunc* TitleCompleted;
	NullSubFunc* TitleLaunched;
	NullSubFunc* ValhallaSign;
	NullSubFunc* ViewOffer;
	NullSubFunc* VIPStatusEarned;
	NullSubFunc* WhatAboutTanksDestroyed;
	NullSubFunc* WonWarGame;
	NullSubFunc* ZanzibarSign;
	NullSubFunc* EnemyDefeated_0;
	NullSubFunc* Member114;
	NullSubFunc* Member115;
	NullSubFunc* Member116;
	NullSubFunc* Member117;
	NullSubFunc* Member118;
	NullSubFunc* Member119;
	__int64(__fastcall* Member120)(GameEvents*, _QWORD);
	NullSubFunc* Member121;
	GUID* (__fastcall* GetGuid)(GameEvents*, GUID*);
	NullSubFunc* Member123;
	NullSubFunc* Member124;
	NullSubFunc* Member125;
};

/* 20 */
typedef unsigned __int16 WORD;


/* 25 */
typedef _LIST_ENTRY LIST_ENTRY;



/* 522 */
struct UnknownStringType
{
	char data[48];
};

/* 523 */
#pragma pack(push, 1)
struct GameLauncher
{
	_DWORD dword0;
	_DWORD dword1;
	char unknownStruct0[177976];
	_DWORD dword2;
	_DWORD dword3;
	_QWORD qword0;
	_QWORD qword1;
	char unknownStruct1[48];
	_QWORD qword2;
	_QWORD qword3;
	_QWORD qword4;
	_DWORD dword4;
	_DWORD dword5;
	_QWORD qword5;
	_QWORD qword6;
	_WORD word0;
	_WORD word1;
	_WORD word2;
	_WORD word3;
	_QWORD qword7;
	_DWORD dword6;
	_DWORD dword7;
};
#pragma pack(pop)



struct LanguageShortstrings
{
	wchar_t a[0x55];
	wchar_t b[0x55];
	wchar_t c[0x55];
};

struct struct_b1_memzero
{
	struct_b1_memzero(size_t size)
	{
		memset(this, 0, size);
	}
};

#pragma pack(push, 1)
struct __cppobj struct_b1 : struct_b1_memzero
{
	struct_b1()
		: struct_b1_memzero(sizeof(struct_b1))
		, unknown0(1)
		//gap0
		, dword2B40C(182)
		, unsigned2B410(0)
		//gap2B414
		, qword2B430(0)
		, dword2B438(0)
		//gap2B43C
		, unknownQword(0)
		//gap2B448
		, a()
		, b(1)
		//gap2B460
		, byte2B680(0)
		, wchar2B690(0)
		//unknown6bytes0
		, languageString(L"en-US")
		//unknown6bytes1
		//phinstance__2B748
		, dword2B750(1525022720)
		, dword2B754(32763)
		//gap2B758
		//pqword2B798
		, dword2B7A0(812910640)
		, qword2B7A8(47244641008)
	{
		memset(gap0, 0, sizeof(gap0));
		memset(gap2B414, 0, sizeof(gap2B414));
		memset(gap2B43C, 0, sizeof(gap2B43C));
		memset(gap2B448, 0, sizeof(gap2B448));
		memset(gap2B460, 0, sizeof(gap2B460));
		memset(gap2B758, 0, sizeof(gap2B758));
	}

	_DWORD unknown0;
	_BYTE gap0[177152];
	_DWORD dword2B40C;
	unsigned int unsigned2B410;
	_BYTE gap2B414[28];
	_QWORD qword2B430;
	_DWORD dword2B438;
	_BYTE gap2B43C[4];
	_QWORD unknownQword;
	_BYTE gap2B448[8];
	_QWORD a;
	_QWORD b;
	_BYTE gap2B460[544];
	_BYTE byte2B680;
	__declspec(align(16)) wchar_t wchar2B690;
	_BYTE unknown6bytes0[6];
	wchar_t languageString[85];
	_BYTE unknown6bytes1[6];
	HMODULE phinstance__2B748;
	_DWORD dword2B750;
	_DWORD dword2B754;
	_BYTE gap2B758[64];
	_QWORD* pqword2B798;
	_DWORD dword2B7A0;
	_QWORD qword2B7A8;
};
#pragma pack(pop)