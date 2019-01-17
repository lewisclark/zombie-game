#include "renderer.h"

game::Renderer::~Renderer() {
	Destroy();
}

game::Renderer::Renderer(SDL_Renderer* sdlrenderer) :
	m_sdlrenderer(sdlrenderer) {
	
}

void game::Renderer::Destroy() {
	SDL_DestroyRenderer(m_sdlrenderer);
}
