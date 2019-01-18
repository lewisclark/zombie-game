#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL2/SDL.h>

#include <thread>
#include <vector>

#include "key.h"

namespace game {
	class InputManager {
		public:
		InputManager();

		void ProcessInput();
		bool IsQuitPolled();
		bool IsKeyDown(Key k);

		private:
		bool m_quitpolled = false;
	};
}

#endif
