#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "renderer.h"
#include "world.h"

namespace game {
	class DrawManager {
		public:
		DrawManager(Renderer* w);

		void DrawMenu();
		void DrawWorld(World* world);
		void DrawPlayerInfo(Player* p); // Draw player info on right of screen (atk, str, hp, skill points, etc)
		
		private:
		void DrawEntities(const std::array<Entity*, game::MAX_ENTITIES>& entities);

		Renderer* m_renderer;
	};
}

#endif
