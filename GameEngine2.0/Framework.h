#pragma once
#include <SDL2/SDL.h>
#include "RenderingEngine.h"
#include "Input.h"

struct FrameworkInitializationParams
{
	int screenWidth, screenHeight, refreshRate;
	bool fullscreen = false;
};

class Framework
{
public:
	Framework(FrameworkInitializationParams& params);
	~Framework();
	// Initialize SDL, and GL
	int Init(int width, int height);
	void MainLoop();
	
private:
	RenderingEngine m_renderer;
	Input m_input;
	static void PrintFrameCount(int frameCount);
};

