/* MIT License

Copyright (c) 2019 Lewis Clark

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */


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
