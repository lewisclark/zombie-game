#include "character.h"

game::Character::~Character() {

}

void game::Character::Think(const InputManager* const inputmgr) {
	Entity::Think(inputmgr);
}

bool game::Character::IsValid() const {
	return Entity::IsValid();
}
