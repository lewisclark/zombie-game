#include "inputmanager.h"

game::InputManager::InputManager() {
	m_threadcheckinput = std::thread(&game::InputManager::CheckInput, this);
}

void game::InputManager::CheckInput() {
	while (true) {
		char key = getch();

		if (key == ERR)
			continue;

		//std::cout << "Key press: " << key << " (" << (int)key << ")" << "\n"; // debug
	}
}
