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
