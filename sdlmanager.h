#ifndef SDLMANAGER_H
#define SDLMANAGER_H

#include <SDL2/SDL.h>

#include <memory>

#include "window.h"
#include "renderer.h"

namespace game {
	class SDLManager {
		public:
		~SDLManager();

		bool Init();
		Window* CreateWindow();
		Renderer* CreateRenderer();

		private:
		std::unique_ptr<Window> m_window = nullptr;
		std::unique_ptr<Renderer> m_renderer = nullptr;
	};
}

#endif
