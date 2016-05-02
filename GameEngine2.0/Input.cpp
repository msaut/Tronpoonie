#include "Input.h"

Input::Input()
{
	m_mouseDelta.x = 0;
	m_mouseDelta.y = 0;

	m_keys[SDLK_0] = false;
	m_keys[SDLK_1] = false;
	m_keys[SDLK_2] = false;
	m_keys[SDLK_3] = false;
	m_keys[SDLK_4] = false;
	m_keys[SDLK_5] = false;
	m_keys[SDLK_6] = false;
	m_keys[SDLK_7] = false;
	m_keys[SDLK_8] = false;
	m_keys[SDLK_9] = false;
	m_keys[SDLK_a] = false;
	m_keys[SDLK_QUOTE] = false;
	m_keys[SDLK_b] = false;
	m_keys[SDLK_BACKSLASH] = false;
	m_keys[SDLK_BACKSPACE] = false;
	m_keys[SDLK_c] = false;
	m_keys[SDLK_CAPSLOCK] = false;
	m_keys[SDLK_COMMA] = false;
	m_keys[SDLK_d] = false;
	m_keys[SDLK_DELETE] = false;
	m_keys[SDLK_DOWN] = false;
	m_keys[SDLK_e] = false;
	m_keys[SDLK_END] = false;
	m_keys[SDLK_EQUALS] = false;
	m_keys[SDLK_ESCAPE] = false;
	m_keys[SDLK_f] = false;
	m_keys[SDLK_F1] = false;
	m_keys[SDLK_F10] = false;
	m_keys[SDLK_F11] = false;
	m_keys[SDLK_F12] = false;
	m_keys[SDLK_F2] = false;
	m_keys[SDLK_F3] = false;
	m_keys[SDLK_F4] = false;
	m_keys[SDLK_F5] = false;
	m_keys[SDLK_F6] = false;
	m_keys[SDLK_F7] = false;
	m_keys[SDLK_F8] = false;
	m_keys[SDLK_F9] = false;
	m_keys[SDLK_g] = false;
	m_keys[SDLK_BACKQUOTE] = false;
	m_keys[SDLK_h] = false;
	m_keys[SDLK_HOME] = false;
	m_keys[SDLK_i] = false;
	m_keys[SDLK_INSERT] = false;
	m_keys[SDLK_j] = false;
	m_keys[SDLK_k] = false;
	m_keys[SDLK_KP_0] = false;
	m_keys[SDLK_KP_1] = false;
	m_keys[SDLK_KP_2] = false;
	m_keys[SDLK_KP_3] = false;
	m_keys[SDLK_KP_4] = false;
	m_keys[SDLK_KP_5] = false;
	m_keys[SDLK_KP_6] = false;
	m_keys[SDLK_KP_7] = false;
	m_keys[SDLK_KP_8] = false;
	m_keys[SDLK_KP_9] = false;
	m_keys[SDLK_KP_DIVIDE] = false;
	m_keys[SDLK_KP_ENTER] = false;
	m_keys[SDLK_KP_MINUS] = false;
	m_keys[SDLK_KP_MULTIPLY] = false;
	m_keys[SDLK_KP_PERIOD] = false;
	m_keys[SDLK_KP_PLUS] = false;
	m_keys[SDLK_l] = false;
	m_keys[SDLK_LALT] = false;
	m_keys[SDLK_LCTRL] = false;
	m_keys[SDLK_LEFT] = false;
	m_keys[SDLK_LEFTBRACKET] = false;
	m_keys[SDLK_LGUI] = false;
	m_keys[SDLK_LSHIFT] = false;
	m_keys[SDLK_m] = false;
	m_keys[SDLK_MINUS] = false;
	m_keys[SDLK_n] = false;
	m_keys[SDLK_NUMLOCKCLEAR] = false;
	m_keys[SDLK_o] = false;
	m_keys[SDLK_p] = false;
	m_keys[SDLK_PAGEDOWN] = false;
	m_keys[SDLK_PAGEUP] = false;
	m_keys[SDLK_PAUSE] = false;
	m_keys[SDLK_PERIOD] = false;
	m_keys[SDLK_PRINTSCREEN] = false;
	m_keys[SDLK_q] = false;
	m_keys[SDLK_r] = false;
	m_keys[SDLK_RALT] = false;
	m_keys[SDLK_RCTRL] = false;
	m_keys[SDLK_RETURN] = false;
	m_keys[SDLK_RGUI] = false;
	m_keys[SDLK_RIGHT] = false;
	m_keys[SDLK_RIGHTBRACKET] = false;
	m_keys[SDLK_RSHIFT] = false;
	m_keys[SDLK_s] = false;
	m_keys[SDLK_SCROLLLOCK] = false;
	m_keys[SDLK_SEMICOLON] = false;
	m_keys[SDLK_SLASH] = false;
	m_keys[SDLK_SPACE] = false;
	m_keys[SDLK_t] = false;
	m_keys[SDLK_TAB] = false;
	m_keys[SDLK_u] = false;
	m_keys[SDLK_UP] = false;
	m_keys[SDLK_v] = false;
	m_keys[SDLK_w] = false;
	m_keys[SDLK_x] = false;
	m_keys[SDLK_y] = false;
	m_keys[SDLK_z] = false;

	m_mouseButtons[SDL_BUTTON_LEFT] = false;
	m_mouseButtons[SDL_BUTTON_MIDDLE] = false;
	m_mouseButtons[SDL_BUTTON_RIGHT] = false;
}


Input::~Input()
{
}


bool Input::Poll()
{
	SDL_Event event;
	Point lastMousePosition = m_mousePosition;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			m_keys[event.key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			m_keys[event.key.keysym.sym] = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			m_mouseButtons[event.button.button] = true;
			break;
		case SDL_MOUSEBUTTONUP:
			m_mouseButtons[event.button.button] = false;
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;
		case SDL_QUIT:
			return false;
		default:
			break;
		}
	}

	m_mouseDelta.x = lastMousePosition.x - m_mousePosition.x;
	m_mouseDelta.y = lastMousePosition.y - m_mousePosition.y;

	return true;
}

bool Input::IsKeyPressed(Uint32 key)
{
	return m_keys[key];
}

bool Input::IsButtonPressed(Uint8 button)
{
	return m_mouseButtons[button];
}

Point Input::GetMousePosition()
{
	return m_mousePosition;
}

Point Input::GetMouseDelta()
{
	return m_mouseDelta;
}
