#include "inputmanager.h"

game::InputManager::InputManager() {
	m_threadcheckinput = std::thread(&game::InputManager::CheckInput, this);
}

void game::InputManager::CheckInput() {
	while (true) {
		char key = getch();

		if (key == ERR)
			continue;

		m_inputs.push_back(key);
	}
}

const std::vector<char> game::InputManager::GetStoredInput() const {
	return m_inputs;
}

void game::InputManager::ClearStoredInput() {
	m_inputs.clear();
}
