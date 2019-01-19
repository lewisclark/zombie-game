#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL2/SDL.h>

#include <thread>
#include <vector>

#include "logger.h"
#include "key.h"
#include "position.h"

namespace game {
	class InputManager {
		public:
		InputManager();

		void Loop();
		bool IsQuitPolled() const;
		bool WasKeyPressed(const Key k) const;
		bool WasKeyReleased(const Key k) const;
		bool IsKeyDown(const Key k) const;
		bool IsClicking() const; // Returns true for either left or right click
		Position GetMousePos() const;

		private:
		void DoPoll();
		bool IsKeyDown(const Key k, const std::uint8_t* const keystate) const;

		bool m_quitpolled = false;

		// keyboard
		const std::uint8_t* m_keystate = nullptr;
		std::uint8_t m_prevkeystate[SDL_NUM_SCANCODES];

		// mouse
		std::uint32_t m_mousestate;
		std::uint32_t m_prevmousestate;
		Position m_mousepos;
	};
}

#endif
