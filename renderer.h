#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

namespace game {
	class Renderer {
		public:
		Renderer(SDL_Renderer* sdlrenderer);
		~Renderer();

		void Destroy();

		private:
		SDL_Renderer* m_sdlrenderer = nullptr;
	};
}

#endif
