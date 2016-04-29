#include "Framework.h"
#include <iostream>

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
	while (m_input.IsRunning())
	{
		m_input.Poll();
		if (m_input.IsKeyPressed(SDLK_w))
		{
			std::cout << "W key pressed" << std::endl;
		}
		if (m_input.IsKeyPressed(SDLK_s))
		{
			std::cout << "S key pressed" << std::endl;
		}
		m_renderer.Update(0);
	}
}
