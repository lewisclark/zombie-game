#include "position.h"

game::Position::Position() :
	m_x(0), m_y(0) {

}

game::Position::Position(const int& x, const int& y) :
	m_x(x), m_y(y) {

}

const int& game::Position::GetX() const {
	return m_x;
}

const int& game::Position::GetY() const {
	return m_y;
}

void game::Position::SetX(const int& x) {
	m_x = x;
}

void game::Position::SetY(const int& y) {
	m_y = y;
}





game::Size::Size() :
	m_w(0), m_h(0) {

}

game::Size::Size(const int& w, const int& h) :
	m_w(w), m_h(h) {

}

const int& game::Size::GetW() const {
	return m_w;
}

const int& game::Size::GetH() const {
	return m_h;
}

void game::Size::SetW(const int& w) {
	m_w = w;
}

void game::Size::SetH(const int& h) {
	m_h = h;
}
