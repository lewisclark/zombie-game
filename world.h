#ifndef WORLD_H
#define WORLD_H

#include <memory>

#include "globals.h"
#include "entities/entityfactory.h"

namespace game {
	class World {
		public:
		World(const Size& world_size);

		void Initialize();
		void Think(const InputManager* const inputmgr);

		EntityFactory* GetEntityFactory();

		private:
		std::unique_ptr<EntityFactory> m_entfactory;
		const Size& m_world_size;
	};
}

#endif
