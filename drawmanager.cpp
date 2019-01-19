#include "drawmanager.h"

game::DrawManager::DrawManager(Renderer* ren) :
	m_renderer(ren) {

}

void game::DrawManager::DrawWorld(World* world) {
	m_renderer->SetDrawColor(42, 42, 42, 255);
	m_renderer->Clear();

	DrawEntities(world->GetEntities());

	m_renderer->Present();
}

void game::DrawManager::DrawEntities(const std::array<Entity*, game::MAX_ENTITIES>& entities) {
	for (Entity* e : entities) {
		if (e && e->IsValid()) {
			e->Draw(m_renderer);
		}
	}
}
