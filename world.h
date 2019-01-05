#ifndef WORLD_H
#define WORLD_H

#include <array>
#include <memory>
#include <algorithm>

#include "player.h"
#include "zombie.h"
#include "item.h"

namespace game {
	// Maximum amount of objects that can exist in a world instance
	const int MAX_ZOMBIES = 32;
	const int MAX_ITEMS = 12;
	const int MAX_PLAYERS = 1; // localplayer
	const int MAX_CHARACTERS = MAX_PLAYERS + MAX_ZOMBIES;
	const int MAX_ENTITIES = MAX_CHARACTERS + MAX_ITEMS;

	class World {
		public:
		World();
		void Initialize();
		void Update();			// Update positions of player, zombies, health, etc.

		// Returning a vector instead of array because I cannot find a simple way to combine multiple arrays into a single one
		std::array<Entity*, MAX_ENTITIES> GetEntities();

		private:
		std::unique_ptr<Player> m_localplayer;
		std::array<std::unique_ptr<Zombie>, MAX_ZOMBIES> m_zombies;
		std::array<std::unique_ptr<Item>, MAX_ITEMS> m_items;
	};
}

#endif
