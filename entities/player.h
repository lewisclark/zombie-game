#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

namespace game {
	class Player : public Character {
		public:
		void Think(const InputManager* const inputmgr);
		bool IsValid() const;
		void Draw(Renderer* ren);

		private:
	};
}

#endif
