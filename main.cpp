#include "main.h"

int main() {
	using namespace game;

	logger = std::make_unique<Logger>("shooter.log");

	auto sdlmanager = std::make_unique<SDLManager>();
	
	if (!sdlmanager->Init()) {
		return 1;
	}

	Window* win = sdlmanager->CreateWindow();

	if (!win) {
		return 1;
	}

	auto renderer = win->CreateRenderer(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer) {
		return 1;
	}

	auto game = std::make_unique<Game>(renderer);

	while (!game->ShouldQuit()) {
		game->Loop();
	}

	return 0;
}
