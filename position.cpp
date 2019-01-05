#include "position.h"

game::Position::Position() {
	m_x = 0;
	m_y = 0;
}

game::Position::Position(int x, int y) {
	m_x = x;
	m_y = y;
}

int game::Position::GetX() {
	return m_x;
}

int game::Position::GetY() {
	return m_y;
}

void game::Position::SetX(int x) {
	m_x = x;
}

void game::Position::SetY(int y) {
	m_y = y;
}





game::Size::Size() {
	m_w = 0;
	m_h = 0;
}

game::Size::Size(int w, int h) {
	m_w = w;
	m_h = h;
}

int game::Size::GetW() {
	return m_w;
}

int game::Size::GetH() {
	return m_h;
}

void game::Size::SetW(int w) {
	m_w = w;
}

void game::Size::SetH(int h) {
	m_h = h;
}
