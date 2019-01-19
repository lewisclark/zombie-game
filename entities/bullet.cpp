#include "bullet.h"

void game::Bullet::Think(const InputManager* const inputmgr) {
	Projectile::Think(inputmgr);
}

bool game::Bullet::IsValid() const {
	return Projectile::IsValid();
}
