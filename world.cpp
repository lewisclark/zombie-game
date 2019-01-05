#include "world.h"

game::World::World() {
	Initialize();
}

void game::World::Initialize() {
	m_localplayer = std::make_unique<Player>();

	// Temporarily fill zombie/item arrays for debugging & testing purposes
	std::generate(m_zombies.begin(), m_zombies.end(), []() {
		return std::make_unique<Zombie>();
	});

	std::generate(m_items.begin(), m_items.end(), []() {
		return std::make_unique<Item>();
	});
}

void game::World::Update() {
	for (Entity* e : GetEntities()) {
		if (e && e->IsValid()) {
			e->Think();
		}
	}
}

std::array<game::Entity*, game::MAX_ENTITIES> game::World::GetEntities() {
	std::array<game::Entity*, game::MAX_ENTITIES> entities;
	entities.fill(nullptr);

	int i = 0;

	entities[i] = m_localplayer.get();

	for (int j = 0; j < MAX_ZOMBIES; j++) {
		entities[++i] = m_zombies.at(j).get();
	}

	for (int j = 0; j < MAX_ITEMS; j++) {
		entities[++i] = m_items.at(j).get();
	}

	return entities;
}
