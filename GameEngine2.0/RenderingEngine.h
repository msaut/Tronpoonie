#pragma once
#include "Display.h"
class RenderingEngine
{
public:
	RenderingEngine(int width, int height);
	~RenderingEngine();
	int Update(int delta);
private:
	Display m_display;
};

