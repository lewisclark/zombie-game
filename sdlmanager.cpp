#include "sdlmanager.h"

game::SDLManager::~SDLManager() {
	if (m_window) {
		m_window->Destroy();
	}

	if (m_renderer) {
		m_renderer->Destroy();
	}

	SDL_Quit();
}

bool game::SDLManager::Init() {
	return SDL_Init(SDL_INIT_VIDEO) ? false : true;
}

game::Window* game::SDLManager::CreateWindow() {
	SDL_Window* sdlwin = SDL_CreateWindow("Zombie Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	if (!sdlwin) {
		return nullptr;
	}

	m_window = std::make_unique<Window>(sdlwin);

	return m_window.get();
}

game::Renderer* game::SDLManager::CreateRenderer() {
	SDL_Renderer* sdlren = SDL_CreateRenderer(m_window->GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!sdlren) {
		return nullptr;
	}

	m_renderer = std::make_unique<Renderer>(sdlren);

	return m_renderer.get();
}
