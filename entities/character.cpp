#include "character.h"

game::Character::Character() {
	SetSize(Size(10, 10));
}

game::Character::~Character() {

}

void game::Character::Think(const InputManager* const inputmgr) {
	Entity::Think(inputmgr);
}

bool game::Character::IsValid() const {
	return Entity::IsValid();
}

const int& game::Character::GetStrength() const {
	return m_strength;
}

const int& game::Character::GetDefence() const {
	return m_defence;
}

const int& game::Character::GetSpeed() const {
	return m_speed;
}

void game::Character::SetStrength(const int& strength) {
	m_strength = strength;
}

void game::Character::SetDefence(const int& defence) {
	m_defence = defence;
}

void game::Character::SetSpeed(const int& speed){ 
	m_speed = speed;
}
