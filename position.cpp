#include "position.h"

game::Position::Position() {
	m_x = 0;
	m_y = 0;
}

game::Position::Position(int x, int y) {
	m_x = x;
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
