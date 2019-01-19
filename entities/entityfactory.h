#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <memory>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "player.h"
#include "zombie.h"
#include "item.h"
#include "bullet.h"

namespace game {
	class EntityFactory {
		public:
		EntityFactory(const Size& map_size);

		std::vector<Entity*> GetEntities();

		Player* CreatePlayer();
		Zombie* CreateZombie(bool random_position = false);
		Item* CreateItem();
		Bullet* CreateBullet();

		private:
		Position GetRandomPosition();

		Size m_mapsize;
		std::mt19937 m_rnd;
		std::vector<std::unique_ptr<Player>> m_players;
		std::vector<std::unique_ptr<Zombie>> m_zombies;
		std::vector<std::unique_ptr<Item>> m_items;
		std::vector<std::unique_ptr<Bullet>> m_bullets;
	};
}

#endif
