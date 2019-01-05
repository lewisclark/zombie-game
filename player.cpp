#include "player.h"

void game::Player::Think() {
	Character::Think();
}

bool game::Player::IsValid() {
	return Character::IsValid();
}
