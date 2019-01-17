#include "main.h"

int main() {
	game::logger = std::make_unique<game::Logger>("shooter.log");
	//std::unique_ptr<ncurses::Window> window;

	/*
	try {
		window = ncurses::Initialize();

		game::logger->LogString("Successfully initialized ncurses\n");
	}
	catch (...) {
		game::logger->LogString("Failed to initialize ncurses, stopping...\n");
		ncurses::Kill();

		return 1;
	}
	*/

	auto game = std::make_unique<game::Game>(/*window.get()*/);

	while (true) {
		game->Loop();

		usleep(10000);
	}

	//ncurses::Kill();

	return 0;
}
