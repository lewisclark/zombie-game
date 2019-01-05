#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "position.h"
#include "ncurseswrapper.h"

namespace game {
	class Entity {
		public:
		Entity();
		Entity(std::string name);
		virtual ~Entity();

		void Draw(ncurses::Window* w);

		virtual void Think();
		virtual bool IsValid();

		private:
		void Initialize();

		std::string m_name;
		int m_health;
		int m_max_health;
		Position m_position;
		Size m_size;
	};
}

#endif
