/* MIT License

Copyright (c) 2019 Lewis Clark

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */


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
