#include <Shared\shared-public-pch.h>
#include <MantleLib\mantlelib-public-pch.h>
#include <HaloReachLib\haloreachlib-private-pch.h>
#include <Halo1Lib\halo1lib-private-pch.h>

#define MCCExecutableFileName "MCC-Win64-Shipping_Debug.exe"

const char* Console::s_consoleExecutableName = "MCC";

bool s_isHaloReachHooked = false;
bool s_isHalo1Hooked = false;

void init_lz4lib();
void deinit_lz4lib();

bool initThreadIsHooked = false;
void nullsub() {}


extern void init_halo_reach(Engine engine, Build build);
extern void deinit_halo_reach(Engine engine, Build build);

void haloreach_dll_loaded_callback()
{
	WriteLineVerbose("Halo Reach was loaded!");
	{
		Build build = GameRuntime::GetLibraryBuildVersion(MCCExecutableFileName);
		HaloReachGameHost::InitModifications(build);
	}
}

void halo1_dll_loaded_callback()
{
	WriteLineVerbose("Halo 1 was loaded!");
	{
		Build build = GameRuntime::GetLibraryBuildVersion(MCCExecutableFileName);
		Halo1GameHost::InitModifications(build);
	}
}

typedef FARPROC(__stdcall GetProcAddressFunc)(HMODULE hModule, LPCSTR lpProcName);
GetProcAddressFunc* GetProcAddressPtr = nullptr;
FARPROC __stdcall GetProcAddressHook(HMODULE hModule, LPCSTR lpProcName)
{
	char pModuleFilename[MAX_PATH] = {};
	GetModuleFileNameA(hModule, pModuleFilename, sizeof(pModuleFilename));

	FARPROC farproc = GetProcAddressPtr(hModule, lpProcName);

	if (!s_isHaloReachHooked)
	{
		bool isHaloReach = strstr(pModuleFilename, "haloreach.dll") != nullptr;
		if (isHaloReach)
		{
			s_isHaloReachHooked = true;

			// reset hook states
			initThreadIsHooked = false;

			haloreach_dll_loaded_callback();
		}
	}
	if (!s_isHalo1Hooked)
	{
		bool isHalo1 = strstr(pModuleFilename, "halo1.dll") != nullptr;
		if (isHalo1)
		{
			s_isHalo1Hooked = true;

			// reset hook states
			initThreadIsHooked = false;

			halo1_dll_loaded_callback();
		}
	}

	return farproc;

}

void init_opus()
{
	register_platforms();

	SystemPatch::PatchEnumWindows();

	AllocConsole();
	(void)(freopen("CONOUT$", "w", stdout));

	init_detours();
	{
		static void* OutputDebugStringW_Original;
		create_dll_hook("KERNEL32.dll", "OutputDebugStringW", nullsub, OutputDebugStringW_Original);
		static void* OutputDebugStringA_Original;
		create_dll_hook("KERNEL32.dll", "OutputDebugStringA", nullsub, OutputDebugStringA_Original);
		create_dll_hook("KERNEL32.dll", "GetProcAddress", GetProcAddressHook, GetProcAddressPtr);

		Build build = GameRuntime::GetLibraryBuildVersion(MCCExecutableFileName);
		DataReferenceBase::InitTree(Engine::MCC, build);
		FunctionHookBase::InitTree(Engine::MCC, build);
		GlobalReference::InitTree(Engine::MCC, build);
	}
	end_detours();
}

void deinit_opus()
{

}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		init_lz4lib();
		init_opus();
	}
	break;
	case DLL_PROCESS_DETACH:
	{
		deinit_lz4lib();
		deinit_opus();
	}
	break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

/*int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	Window::SetIcon(LoadIconA(hInstance, ResourcesManager::GetResourceIntResource(ResourceType::Icon)));
	SystemPatch::PatchEnumWindows();

	static bool s_running = true;
	void(*UpdateCallback)() = []()
	{
		Render::BeginFrame(true, &clearColor.x);
		GameLauncher::OpusTick();
		Render::EndFrame();
	};
	void(*DestroyCallback)() = []()
	{
		s_running = false;
	};
	
	Window::Init("Opus", "OpusConsole", "opus");
	Render::Init(hInstance);
	MantleGUI::Init(true);
	GameLauncher::Init();

	Window::RegisterUpdateCallback(UpdateCallback);
	Window::RegisterDestroyCallback(DestroyCallback);
	//MantleGUI::RegisterOnCloseCallback(DestroyCallback);

	while (s_running) Window::Update();

	Window::UnregisterUpdateCallback(UpdateCallback);
	Window::UnregisterDestroyCallback(DestroyCallback);
	//MantleGUI::UnregisterOnCloseCallback(DestroyCallback);

	GameLauncher::Deinit();
	MantleGUI::Deinit();
	Render::Deinit();
	Window::Deinit();

	return 0;
}*/
