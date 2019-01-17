#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

namespace game {
	class Window {
		public:
		Window(SDL_Window* sdlwin);

		SDL_Window* GetSDLWindow();

		private:
		SDL_Window* m_sdlwin = nullptr;
	};
}

#endif
