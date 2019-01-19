#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

namespace game {
	class Player : public Character {
		public:
		void Think();
		bool IsValid() const;

		private:
	};
}

#endif
