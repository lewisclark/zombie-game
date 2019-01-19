#ifndef WORLD_H
#define WORLD_H

#include <array>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>

#include "globals.h"
#include "entities/player.h"
#include "entities/zombie.h"
#include "entities/item.h"

namespace game {
	class World {
		public:
		World(const Size& world_size);
		void Initialize();
		void Think(const InputManager* const inputmgr);
		void ProcessInput(const std::vector<char>& inputs);

		std::array<Entity*, MAX_ENTITIES> GetEntities();

		private:
		const Size& m_world_size;
		std::unique_ptr<Player> m_localplayer;
		std::array<std::unique_ptr<Zombie>, MAX_ZOMBIES> m_zombies;
		std::array<std::unique_ptr<Item>, MAX_ITEMS> m_items;
	};
}

#endif
