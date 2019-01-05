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
	m_position = game::Position();
}

void game::Entity::Draw(ncurses::Window*) {

}

void game::Entity::Think() {

}

bool game::Entity::IsValid() {
	return true;
}
