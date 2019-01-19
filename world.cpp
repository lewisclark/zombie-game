#include "world.h"

game::World::World(const Size& world_size) :
	m_world_size(world_size) {

	Initialize();
}

void game::World::Initialize() {
	m_localplayer = std::make_unique<Player>();
	m_localplayer->SetName("Player");
	m_localplayer->SetPosition(Position(m_world_size.GetW() / 2, m_world_size.GetH() / 2));

	auto time = std::chrono::high_resolution_clock::now();

	std::mt19937 r;
	r.seed((std::chrono::high_resolution_clock::now() - time).count());
	std::uniform_int_distribution<int> dis_x(0, m_world_size.GetW());
	std::uniform_int_distribution<int> dis_y(0, m_world_size.GetH());

	std::generate(m_zombies.begin(), m_zombies.end(), [&]() {
		auto z = std::make_unique<Zombie>();

		z->SetPosition(Position(dis_x(r), dis_y(r)));
		z->SetName("Zombie");

		return z;
	});
}

// TODO: Remove invalid entities
void game::World::Think(const InputManager* const inputmgr) {
	for (Entity* e : GetEntities()) {
		if (e && e->IsValid()) {
			e->Think(inputmgr);
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
