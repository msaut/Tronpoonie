#include <iostream>
#include "Framework.h"
#undef main

int main()
{
	FrameworkInitializationParams params;
	params.screenWidth = 800;
	params.screenHeight = 600;
	Framework framework(params);
	framework.MainLoop();
	return 0;
}