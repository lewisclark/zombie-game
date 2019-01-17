#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL2/SDL.h>

#include <thread>
#include <vector>

namespace game {
	class InputManager {
		public:
		InputManager();

		void ProcessInput();
		bool IsQuitPolled();

		private:
		bool m_quitpolled = false;
	};
}

#endif
