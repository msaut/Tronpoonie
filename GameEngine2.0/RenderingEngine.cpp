#include "RenderingEngine.h"


RenderingEngine::RenderingEngine(int width, int height)
	:m_display(width, height, "Rendering Engine 2.0")
{
}


RenderingEngine::~RenderingEngine()
{
}


int RenderingEngine::Update(int delta)
{
	m_display.Update();
	return 0;
}
