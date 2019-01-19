#include "zombie.h"

void game::Zombie::Think(const InputManager* const inputmgr) {
	Character::Think(inputmgr);
}

bool game::Zombie::IsValid() const {
	return Character::IsValid();
}
