#include "color.h"

game::Color::Color() {

}

game::Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) :
	m_r(r), m_g(g), m_b(b), m_a(a) {

}

game::Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b) :
	m_r(r), m_g(g), m_b(b) {
	
}

std::uint8_t game::Color::GetR() {
	return m_r;
}

std::uint8_t game::Color::GetG() {
	return m_g;
}

std::uint8_t game::Color::GetB() {
	return m_b;
}

std::uint8_t game::Color::GetA() {
	return m_a;
}
