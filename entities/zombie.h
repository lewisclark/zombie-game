#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "character.h"

namespace game {
	class Zombie : public Character {
		public:
		void Think(const InputManager* const inputmgr);
		bool IsValid() const;
		void Draw(Renderer* ren);

		private:
	};
}

#endif
