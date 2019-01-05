#include "main.h"

int main() {
	std::unique_ptr<ncurses::Window> window;

	try {
		window = ncurses::Initialize();
	}
	catch (...) {
		ncurses::Kill();

		return 1;
	}

	auto game = std::make_unique<game::Game>(window.get());

	while (true) {
		game->Loop();

		usleep(10000);
	}

	ncurses::Kill();

	return 0;
}
