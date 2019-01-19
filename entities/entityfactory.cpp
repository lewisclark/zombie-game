/* MIT License

Copyright (c) 2019 Lewis Clark

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */


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

game::Bullet* game::EntityFactory::CreateBullet() {
	m_bullets.push_back(std::make_unique<Bullet>());

	return m_bullets.back().get();
}

game::Position game::EntityFactory::GetRandomPosition() {
	std::uniform_int_distribution<int> dis_x(0, m_mapsize.GetW());
	std::uniform_int_distribution<int> dis_y(0, m_mapsize.GetH());

	return Position(dis_x(m_rnd), dis_y(m_rnd));
}
