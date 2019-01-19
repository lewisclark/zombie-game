/* MIT License

Copyright (c) 2019 Lewis Clark

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */


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
