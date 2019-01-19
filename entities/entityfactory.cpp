#include "entityfactory.h"

game::EntityFactory::EntityFactory(const Size& map_size) :
	m_mapsize(map_size) {

	auto time = std::chrono::high_resolution_clock::now();
	m_rnd.seed((std::chrono::high_resolution_clock::now() - time).count());
}

std::vector<game::Entity*> game::EntityFactory::GetEntities() {
	std::vector<Entity*> entities;

	for (const auto& p : m_players) {
		entities.push_back(p.get());
	}

	for (const auto& z : m_zombies) {
		entities.push_back(z.get());
	}

	for (const auto& i : m_items) {
		entities.push_back(i.get());
	}

	return entities;
}

game::Player* game::EntityFactory::CreatePlayer() {
	m_players.push_back(std::make_unique<Player>());

	return m_players.back().get();
}

game::Zombie* game::EntityFactory::CreateZombie(bool random_position) {
	m_zombies.push_back(std::make_unique<Zombie>());

	if (random_position) {
		m_zombies.back()->SetPosition(GetRandomPosition());
	}

	return m_zombies.back().get();
}

game::Item* game::EntityFactory::CreateItem() {
	m_items.push_back(std::make_unique<Item>());

	return m_items.back().get();
}

game::Position game::EntityFactory::GetRandomPosition() {
	std::uniform_int_distribution<int> dis_x(0, m_mapsize.GetW());
	std::uniform_int_distribution<int> dis_y(0, m_mapsize.GetH());

	return Position(dis_x(m_rnd), dis_y(m_rnd));
}
