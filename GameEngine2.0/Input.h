#pragma once
#include <SDL2\SDL.h>
#include <unordered_map>

struct Point
{
	int x;
	int y;
};

class Input
{
public:
	Input();
	~Input();
	int Poll();
	bool IsRunning();
	bool IsKeyPressed(Uint32 key);
	bool IsButtonPressed(Uint8 button);
	Point GetMousePosition();
	Point GetMouseDelta();
private:
	std::unordered_map<Uint32, bool> m_keys;
	std::unordered_map<Uint8, bool> m_mouseButtons;
	Point m_mousePosition;
	Point m_mouseDelta;
	bool m_isRunning;
};

