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

		private:
		std::unique_ptr<Window> m_window = nullptr;
	};
}

#endif
