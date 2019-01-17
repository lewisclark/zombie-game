#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

#include <memory>
#include <vector>
#include <cinttypes>

#include "renderer.h"

namespace game {
	class Window {
		public:
		Window(SDL_Window* sdlwin);
		~Window();

		Renderer* CreateRenderer(std::uint32_t flags);
		void Destroy();

		private:
		SDL_Window* m_sdlwin = nullptr;
		std::vector<std::unique_ptr<Renderer>> m_renderers;
	};
}

#endif
