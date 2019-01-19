#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

namespace game {
	class Projectile : public Entity {
		public:
		virtual ~Projectile();

		virtual void Think(const InputManager* const inputmgr);
		virtual bool IsValid() const;

		private:
	};
}

#endif
