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


#include "color.h"

game::Color::Color() {

}

game::Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) :
	m_r(r), m_g(g), m_b(b), m_a(a) {

}

game::Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b) :
	m_r(r), m_g(g), m_b(b) {
	
}

std::uint8_t game::Color::GetR() const {
	return m_r;
}

std::uint8_t game::Color::GetG() const {
	return m_g;
}

std::uint8_t game::Color::GetB() const {
	return m_b;
}

std::uint8_t game::Color::GetA() const {
	return m_a;
}
