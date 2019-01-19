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


#include "entity.h"

game::Entity::Entity() {

}

game::Entity::Entity(std::string name) :
	m_name(name) {

}

game::Entity::~Entity() {

}

void game::Entity::Draw(Renderer*) {

}

void game::Entity::Think(const InputManager* const) {

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

const game::Position& game::Entity::GetPosition() const {
	return m_position;
}

void game::Entity::SetPosition(const Position& p) {
	m_position = p;
}

const game::Size& game::Entity::GetSize() const {
	return m_size;
}

void game::Entity::SetSize(const Size& s) {
	m_size = s;
}
