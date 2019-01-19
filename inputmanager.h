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
