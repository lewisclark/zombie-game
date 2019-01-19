#include "inputmanager.h"

game::InputManager::InputManager() {

}

void game::InputManager::Loop() {
	if (m_keystate) {
		for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
			m_prevkeystate[i] = m_keystate[i];
		}
	}

	m_prevmousestate = m_mousestate;

	DoPoll(); // Calls SDL_PumpEvents for us

	m_keystate = SDL_GetKeyboardState(nullptr);

	int x, y;
	m_mousestate = SDL_GetMouseState(&x, &y);
	m_mousepos = Position(x, y);
}

void game::InputManager::DoPoll() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				m_quitpolled = true;
				break;	
		}
	}
}

bool game::InputManager::IsQuitPolled() const {
	return m_quitpolled;
}

bool game::InputManager::WasKeyPressed(const Key k) const {
	return !IsKeyDown(k, m_prevkeystate) && IsKeyDown(k, m_keystate);
}

bool game::InputManager::WasKeyReleased(const Key k) const {
	return IsKeyDown(k, m_prevkeystate) && !IsKeyDown(k, m_keystate);
}

bool game::InputManager::IsKeyDown(const Key k) const {
	return IsKeyDown(k, m_keystate);
}

bool game::InputManager::IsKeyDown(const Key k, const std::uint8_t* const keystate) const {
	return keystate[k] != 0;
}

bool game::InputManager::IsClicking() const {
	return (m_mousestate & SDL_BUTTON(SDL_BUTTON_LEFT)) || (m_mousestate & SDL_BUTTON(SDL_BUTTON_RIGHT));
}

game::Position game::InputManager::GetMousePos() const {
	return m_mousepos;
}
