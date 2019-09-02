#include "haloshared-private-pch.h"

HICON CustomWindow::s_hIcon = NULL;
HWND CustomWindow::s_hHWND = NULL;
HINSTANCE CustomWindow::s_hInstance = NULL;
void(*CustomWindow::s_OnDestroyCallback)() = nullptr;

HWND CustomWindow::GetWindowHandle()
{
	return s_hHWND;
}

HICON CustomWindow::GetIcon()
{
	return s_hIcon;
}

void CustomWindow::SetIcon(HICON hIcon)
{
	s_hIcon = hIcon;
}

void CustomWindow::SetOnDestroyCallback(void(callback)())
{
	s_OnDestroyCallback = callback;
}

void CustomWindow::OnDestroyCallback()
{
	if (s_OnDestroyCallback)
	{
		s_OnDestroyCallback();
	}
}

LRESULT CALLBACK CustomWindow::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	DebugUI::WndProc(hwnd, msg, wParam, lParam);

	switch (msg)
	{
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
		{
			return 0;
		}
		break;
	case WM_DESTROY:
		OnDestroyCallback();
		PostQuitMessage(WM_QUIT);
		break;
	case WM_SIZE:
		// #TODO: tell game to resize
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void CustomWindow::Init()
{
	SetProcessDPIAware();

	s_hInstance = GetModuleHandle(NULL);

	// Register the window class.

	WNDCLASS wc = { };

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = s_hInstance;
	wc.hIcon = CustomWindow::GetIcon();
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "opus_window_class";

	RegisterClass(&wc);

	// Create the window.

	s_hHWND = CreateWindowEx(
		0,                              // Optional window styles.
		"opus_window_class",                     // Window class
		"Opus",    // Window text
		WS_OVERLAPPEDWINDOW,            // Window style

		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,       // Parent window    
		NULL,       // Menu
		s_hInstance,  // Instance handle
		NULL        // Additional application data
	);

	if (s_hHWND == NULL)
	{
		int err = GetLastError();
		FATAL_ERROR("Failed to create window [%i]", err);
	}

	ShowWindow(s_hHWND, SW_SHOW);
	SetFocus(s_hHWND);
}

void CustomWindow::Deinit()
{
	CloseWindow(s_hHWND);
	UnregisterClassA("opus_window_class", s_hInstance);
}

void CustomWindow::Update()
{
	MSG msg = {};

	while (PeekMessage(&msg, s_hHWND, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (GetAsyncKeyState(VK_F11))
	{
		OnDestroyCallback();
	}
}

