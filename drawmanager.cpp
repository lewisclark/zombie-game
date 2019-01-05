#include "drawmanager.h"

void game::DrawManager::DrawWorld(World* world) {
	ncurses::Print("Yeet");

	DrawEntities(world->GetEntities());
}

void game::DrawManager::DrawEntities(std::array<Entity*, game::MAX_ENTITIES> entities) {
	for (Entity* e : entities) {
		if (e && e->IsValid()) {
			e->Draw();
		}
	}
}
