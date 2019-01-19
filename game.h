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


#ifndef GAME_H
#define GAME_H

#include <memory>

#include "renderer.h"
#include "inputmanager.h"
#include "world.h"
#include "drawmanager.h"
#include "logger.h"

// Represents a game instance, holding everything pertaining to the game session

namespace game {
	class Game {
		public:
		Game(Renderer* w);
		void Loop();
		bool ShouldQuit();

		private:
		void Initialize(Renderer* w); 		// Called at application startup
		void NewGame();			// Called to create a new game (after main menu)
		void DestroyGame();		// Called to destroy an active game (to exit to main menu)

		std::unique_ptr<InputManager> m_inputmgr;
		std::unique_ptr<World> m_world;
		std::unique_ptr<DrawManager> m_drawmgr;
		Renderer* m_renderer; // Window for the world to display players, zombies, items, etc.
		bool m_menuopen;
	};
}

#endif
