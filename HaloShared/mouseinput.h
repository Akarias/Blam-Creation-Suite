#pragma once

enum MouseInputButton
{
	Left,
	Right,
	Middle,
};

class MouseInput
{
public:
	static void Init(HINSTANCE hInstance);
	static void SetSensitivity(float horizontalSensitivity, float verticalSensitivity);
	static bool Read();
	static void Deinit();

	static float GetMouseX();
	static float GetMouseY();
	static bool GetMouseButton(MouseInputButton button);
	static void SetExclusiveMode(bool isExclusive);
	static void Acquire();
private:
	static float s_horizontalSensitivity;
	static float s_verticalSensitivity;
	static IDirectInput8* m_pDirectInput8;
	static IDirectInputDevice8* m_pDirectInput8Mouse;
	static DIMOUSESTATE2 s_mouseState2;
	static std::atomic<DWORD> s_currentAcquireMode;
	static DWORD s_targetAcquireMode;
};
