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

bool game::Renderer::Clear() {
	return SDL_RenderClear(m_sdlrenderer) ? false : true;
}

void game::Renderer::Present() {
	SDL_RenderPresent(m_sdlrenderer);
}

bool game::Renderer::SetDrawColor(const Color& col) {
	return SDL_SetRenderDrawColor(m_sdlrenderer, col.GetR(), col.GetG(), col.GetB(), col.GetA()) ? false : true;
}

bool game::Renderer::SetDrawColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) {
	return SDL_SetRenderDrawColor(m_sdlrenderer, r, g, b, a) ? false : true;
}

bool game::Renderer::DrawRect(int x, int y, int w, int h) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	return SDL_RenderDrawRect(m_sdlrenderer, &rect) ? false : true;
}
