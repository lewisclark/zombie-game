#include "player.h"

void game::Player::Think(const InputManager* const inputmgr) {
	Character::Think(inputmgr);

	if (inputmgr->IsKeyDown(KEY_W)) {
		auto newpos = Position(GetPosition());

		newpos.SetY(newpos.GetY() - GetSpeed());
		SetPosition(newpos);
	}

	if (inputmgr->IsKeyDown(KEY_A)) {
		auto newpos = Position(GetPosition());

		newpos.SetX(newpos.GetX() - GetSpeed());
		SetPosition(newpos);
	}

	if (inputmgr->IsKeyDown(KEY_S)) {
		auto newpos = Position(GetPosition());

		newpos.SetY(newpos.GetY() + GetSpeed());
		SetPosition(newpos);
	}

	if (inputmgr->IsKeyDown(KEY_D)) {
		auto newpos = Position(GetPosition());

		newpos.SetX(newpos.GetX() + GetSpeed());
		SetPosition(newpos);
	}

	if (inputmgr->IsClicking()) {
		Fire(inputmgr->GetMousePos());
	}
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

void game::Player::Fire(const Position&) {

}
