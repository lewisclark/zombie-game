#include "character.h"

game::Character::~Character() {

}

void game::Character::Think() {
	Entity::Think();
}

bool game::Character::IsValid() {
	return Entity::IsValid();
}
