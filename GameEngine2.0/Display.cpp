#include "Display.h"
#include <GL/glew.h>
#include <iostream>

Display::Display(int width, int height, const std::string & title)
{
	// Initialize SDL Video bit
	SDL_InitSubSystem(SDL_INIT_VIDEO);

	// Set sdl attributes (number of colors, double buffer)
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Initialize window
	m_window = SDL_CreateWindow(
		title.c_str(), 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		width,
		height, 
		SDL_WINDOW_OPENGL);

	// Create the GL context giving control of the window to openGl
	m_glContext = SDL_GL_CreateContext(m_window);

	GLenum status = glewInit();

	if (status != GLEW_OK)
	{
		std::cerr << "Glew failed to initialize" << std::endl;
	}

	m_isClosed = false;
}

void Display::Update()
{
	SDL_GL_SwapWindow(m_window);
}

bool Display::IsClosed()
{
	return m_isClosed;
}

Display::~Display()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
}
