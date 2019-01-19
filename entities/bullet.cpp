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
