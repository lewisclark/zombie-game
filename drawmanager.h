#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "window.h"
#include "world.h"

// Responsible for everything drawing related

namespace game {
	class DrawManager {
		public:
		DrawManager(Window* w);

		void DrawMenu();
		void DrawWorld(World* world);
		void DrawPlayerInfo(Player* p); // Draw player info on right of screen (atk, str, hp, skill points, etc)
		
		private:
		void DrawEntities(const std::array<Entity*, game::MAX_ENTITIES>& entities);

		Window* m_window;
	};
}

#endif
