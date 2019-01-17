#include "main.h"

int main() {
	using namespace game;

	logger = std::make_unique<Logger>("shooter.log");

	auto sdlmanager = std::make_unique<SDLManager>();
	sdlmanager->Init();

	if (!sdlmanager->CreateWindow()) {
		return 1;
	}

	auto renderer = sdlmanager->CreateRenderer();

	if (!renderer) {
		return 1;
	}

	auto game = std::make_unique<Game>(renderer);

	while (true) {
		game->Loop();

		usleep(10000);
	}

	return 0;
}
