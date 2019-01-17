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

game::Size game::Renderer::GetCanvasSize() {
	int w, h;
	SDL_GetRendererOutputSize(m_sdlrenderer, &w, &h);
	
	return Size(w, h);
}
