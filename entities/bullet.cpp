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


#include "bullet.h"

game::Bullet::Bullet() {
	SetSize(Size(3, 3));
}

void game::Bullet::Think(const InputManager* const inputmgr) {
	Projectile::Think(inputmgr);
}

bool game::Bullet::IsValid() const {
	return Projectile::IsValid();
}

void game::Bullet::Draw(Renderer* ren) {
	const auto pos = GetPosition();
	const auto size = GetSize();

	ren->SetDrawColor(Color(255, 255, 255));
	ren->DrawRect(pos.GetX() - (size.GetW() / 2), pos.GetY() - (size.GetH() / 2), size.GetW() / 2, size.GetH() / 2);
}
