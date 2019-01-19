#include "projectile.h"

game::Projectile::~Projectile() {

}

void game::Projectile::Think(const InputManager* const inputmgr) {
	Entity::Think(inputmgr);
}

bool game::Projectile::IsValid() const {
	return Entity::IsValid();
}
