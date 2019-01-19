#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL2/SDL.h>

#include <thread>
#include <vector>

#include "logger.h"
#include "key.h"

namespace game {
	class InputManager {
		public:
		InputManager();

		void Loop();
		bool IsQuitPolled() const;
		bool WasKeyPressed(const Key k) const;
		bool WasKeyReleased(const Key k) const;
		bool IsKeyDown(const Key k) const;

		private:
		void DoPoll();
		bool IsKeyDown(const Key k, const std::uint8_t* const keystate) const;

		bool m_quitpolled = false;
		const std::uint8_t* m_keystate = nullptr;
		std::uint8_t m_prevkeystate[SDL_NUM_SCANCODES];
	};
}

#endif
