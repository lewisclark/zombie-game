#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <thread>

#include "ncurseswrapper.h" // debugging, remove.

namespace game {
	class InputManager {
		public:
		InputManager();

		private:
		void CheckInput();

		std::thread m_threadcheckinput;
	};
}

#endif
