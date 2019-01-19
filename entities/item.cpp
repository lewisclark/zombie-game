#include "item.h"

void game::Item::Think(const InputManager* const inputmgr) {
	Entity::Think(inputmgr);
}

bool game::Item::IsValid() const {
	return Entity::IsValid();
}
