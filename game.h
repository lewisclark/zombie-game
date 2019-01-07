#ifndef GAME_H
#define GAME_H

#include <memory>

#include "inputmanager.h"
#include "world.h"
#include "drawmanager.h"
#include "logger.h"

// Represents a game instance, holding everything pertaining to the game session

namespace game {
	class Game {
		public:
		Game(ncurses::Window* w);
		void Loop();

		private:
		void Initialize(ncurses::Window* w); 		// Called at application startup
		void NewGame();			// Called to create a new game (after main menu)
		void DestroyGame();		// Called to destroy an active game (to exit to main menu)
		void Think();
		void ProcessInput(const std::vector<char>& inputs);
		void Draw();

		std::unique_ptr<InputManager> m_inputmgr;
		std::unique_ptr<World> m_world;
		std::unique_ptr<DrawManager> m_drawmgr;
		ncurses::Window* m_window; // Window for the world to display players, zombies, items, etc.
		bool m_menuopen;
	};
}

#endif
