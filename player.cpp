#include "player.h"

void game::Player::Think(const InputManager* const inputmgr) {
	Character::Think(inputmgr);
}

bool game::Player::IsValid() const {
	return Character::IsValid();
}

void game::Player::Draw(Renderer* ren) {
	const auto pos = GetPosition();
	const auto size = GetSize();

	ren->SetDrawColor(Color(255, 255, 0));
	ren->DrawRect(pos.GetX() - (size.GetW() / 2), pos.GetY() - (size.GetH() / 2), size.GetW() / 2, size.GetH() / 2);
}
