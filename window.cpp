#include "window.h"

game::Window::~Window() {
	Destroy();
}

game::Window::Window(SDL_Window* sdlwin) :
	m_sdlwin(sdlwin) {

}

SDL_Window* game::Window::GetSDLWindow() {
	return m_sdlwin;
}

void game::Window::Destroy() {
	SDL_DestroyWindow(m_sdlwin);
}
