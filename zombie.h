#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "character.h"

namespace game {
	class Zombie : public Character {
		public:
		void Think();
		bool IsValid();

		private:
	};
}

#endif
