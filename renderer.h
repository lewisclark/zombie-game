#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

#include <cinttypes>

#include "position.h"
#include "color.h"

namespace game {
	class Renderer {
		public:
		Renderer(SDL_Renderer* sdlrenderer);
		~Renderer();

		void Destroy();
		Size GetCanvasSize();

		bool Clear();
		void Present();
		bool SetDrawColor(const Color& col);
		bool SetDrawColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a);

		private:
		SDL_Renderer* m_sdlrenderer = nullptr;
	};
}

#endif
