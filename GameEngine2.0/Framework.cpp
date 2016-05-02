#include "Framework.h"
#include <iostream>
#include "Timer.h"

Framework::Framework(FrameworkInitializationParams& params)
	:m_input(), 
	m_renderer(params.screenWidth, params.screenHeight) 
{
}

Framework::~Framework()
{
}


// Initialize SDL, and GL
int Framework::Init(int width, int height)
{
	return 0;
}


void Framework::MainLoop()
{
	Timer timer;
	timer.Start();
	timer.SetTimer(1.0, &PrintFrameCount);
	while (m_input.Poll())
	{
		double dt = timer.Tick();
		m_renderer.Update(dt);
	}
}

void Framework::PrintFrameCount(int frameCount)
{
	std::cout << " FPS: " << frameCount << std::endl;
}