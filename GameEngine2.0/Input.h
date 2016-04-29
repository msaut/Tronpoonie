#pragma once
#include <SDL2\SDL.h>
#include <unordered_map>
class Input
{
public:
	Input();
	~Input();
	int Poll();
	bool IsRunning();
	bool IsKeyPressed(Uint32 key);
private:
	std::unordered_map<Uint32, bool> m_keys;
	bool m_isRunning;
};

