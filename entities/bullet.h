#ifndef BULLET_H
#define BULLET_H

#include "projectile.h"

namespace game {
	class Bullet : public Projectile {
		public:
		Bullet();

		void Think(const InputManager* const inputmgr);
		bool IsValid() const;
		void Draw(Renderer* ren);

		private:
	};
}

#endif
