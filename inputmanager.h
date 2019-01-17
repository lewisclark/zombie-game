#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <thread>
#include <vector>

namespace game {
	class InputManager {
		public:
		InputManager();

		const std::vector<char> GetStoredInput() const; // Return by copy to avoid race condition
		void ClearStoredInput();

		private:
		void CheckInput();

		std::thread m_threadcheckinput;
		std::vector<char> m_inputs;
	};
}

#endif
