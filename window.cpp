#include "window.h"

game::Window::~Window() {
	Destroy();
}

game::Window::Window(SDL_Window* sdlwin) :
	m_sdlwin(sdlwin) {

}

game::Renderer* game::Window::CreateRenderer(std::uint32_t flags) {
	SDL_Renderer* sdlren = SDL_CreateRenderer(m_sdlwin, -1, flags);

	if (!sdlren) {
		return nullptr;
	}

	m_renderers.push_back(std::make_unique<Renderer>(sdlren));

	return m_renderers.back().get();
}

void game::Window::Destroy() {
	for (const auto& ren : m_renderers) {
		ren->Destroy();
	}

	SDL_DestroyWindow(m_sdlwin);
}
