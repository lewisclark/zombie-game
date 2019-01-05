#include "drawmanager.h"

void game::DrawManager::DrawWorld(World* world) {
	DrawEntities(world->GetEntities());
}

void game::DrawManager::DrawEntities(const std::array<Entity*, game::MAX_ENTITIES>& entities) {
	for (Entity* e : entities) {
		if (e && e->IsValid()) {
			e->Draw();
		}
	}
}
