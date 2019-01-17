#include "inputmanager.h"

game::InputManager::InputManager() {

}

void game::InputManager::ProcessInput() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				m_quitpolled = true;
				break;	
		}
	}
}

bool game::InputManager::IsQuitPolled() {
	return m_quitpolled;
}
