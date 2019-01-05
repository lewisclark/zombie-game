#include "zombie.h"

void game::Zombie::Think() {
	Character::Think();
}

bool game::Zombie::IsValid() {
	return Character::IsValid();
}
