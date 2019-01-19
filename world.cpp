#include "world.h"

game::World::World(const Size& world_size) :
	m_world_size(world_size) {

	Initialize();
}

void game::World::Initialize() {
	m_entfactory = std::make_unique<EntityFactory>(m_world_size);

	Player* localplayer = m_entfactory->CreatePlayer();
	localplayer->SetPosition(Position(m_world_size.GetW() / 2, m_world_size.GetH() / 2));

	for (int i = 0; i < MAX_ZOMBIES; i++) {
		m_entfactory->CreateZombie(true);
	}
}

// TODO: Remove invalid entities
void game::World::Think(const InputManager* const inputmgr) {
	for (Entity* e : m_entfactory->GetEntities()) {
		if (e && e->IsValid()) {
			e->Think(inputmgr);
		}
	}
}

game::EntityFactory* game::World::GetEntityFactory() {
	return m_entfactory.get();
}
