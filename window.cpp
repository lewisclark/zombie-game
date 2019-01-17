#include "window.h"

game::Window::Window(SDL_Window* sdlwin) :
	m_sdlwin(sdlwin) {

}

SDL_Window* game::Window::GetSDLWindow() {
	return m_sdlwin;
}
