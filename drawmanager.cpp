#include "drawmanager.h"

game::DrawManager::DrawManager(Window* w) :
	m_window(w) {

}

void game::DrawManager::DrawWorld(World* world) {
	/*ncurses::ClearWindow(m_window);*/
	DrawEntities(world->GetEntities());
}

void game::DrawManager::DrawEntities(const std::array<Entity*, game::MAX_ENTITIES>& entities) {
	for (Entity* e : entities) {
		if (e && e->IsValid()) {
			e->Draw(/*m_window*/);
		}
	}
}
