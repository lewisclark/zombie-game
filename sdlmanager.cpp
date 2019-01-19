#include "sdlmanager.h"

game::SDLManager::~SDLManager() {
	if (m_window) {
		m_window->Destroy();
	}

	SDL_Quit();
}

bool game::SDLManager::Init() {
	return SDL_Init(SDL_INIT_VIDEO) ? false : true;
}

game::Window* game::SDLManager::CreateWindow() {
	SDL_Window* sdlwin = SDL_CreateWindow("Zombie Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	if (!sdlwin) {
		return nullptr;
	}

	m_window = std::make_unique<Window>(sdlwin);

	return m_window.get();
}
