#ifndef WORLD_H
#define WORLD_H

#include <array>
#include <memory>
#include <algorithm>
#include <random>

#include "globals.h"
#include "player.h"
#include "zombie.h"
#include "item.h"

namespace game {
	class World {
		public:
		World();
		void Initialize();
		void Think();

		std::array<Entity*, MAX_ENTITIES> GetEntities();

		private:
		std::unique_ptr<Player> m_localplayer;
		std::array<std::unique_ptr<Zombie>, MAX_ZOMBIES> m_zombies;
		std::array<std::unique_ptr<Item>, MAX_ITEMS> m_items;
	};
}

#endif
