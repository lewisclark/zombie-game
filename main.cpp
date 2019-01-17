#include "main.h"

int main() {
	using namespace game;

	logger = std::make_unique<Logger>("shooter.log");

	auto sdlmanager = std::make_unique<SDLManager>();
	sdlmanager->Init();

	sdlmanager->CreateWindow();
	sdlmanager->CreateRenderer();

	//auto game = std::make_unique<Game>(sdlmanager->CreateWindow());

	while (true) {
		//game->Loop();

		usleep(10000);
	}

	//ncurses::Kill();

	return 0;
}
