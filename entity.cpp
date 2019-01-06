#include "entity.h"

game::Entity::Entity() {
	Initialize();
}

game::Entity::Entity(std::string name) {
	Initialize();

	m_name = name;
}

game::Entity::~Entity() {

}

void game::Entity::Initialize() {
	m_name = "<unknown>";
	m_health = 100;
	m_max_health = 100;
}

void game::Entity::Draw(ncurses::Window* w) const {
	ncurses::DrawCharacter(w, m_position.GetY(), m_position.GetX(), m_name.at(0)); // temporary
}

void game::Entity::Think() {

}

bool game::Entity::IsValid() const {
	return true;
}

const std::string& game::Entity::GetName() const {
	return m_name;
}

void game::Entity::SetName(const std::string& name) {
	m_name = name;
}

const int& game::Entity::GetHealth() const {
	return m_health;
}

void game::Entity::SetHealth(const int& health) {
	m_health = health;
}

void game::Entity::Hurt(const int& damage) {
	m_health -= damage;
}

const int& game::Entity::GetMaxHealth() const {
	return m_max_health;
}

void game::Entity::SetMaxHealth(const int& max_health) {
	m_max_health = max_health;
}

game::Position& game::Entity::GetPosition() {
	return m_position;
}

void game::Entity::SetPosition(const Position& p) {
	m_position = p;
}

game::Size& game::Entity::GetSize() {
	return m_size;
}

void game::Entity::SetSize(const Size& s) {
	m_size = s;
}
