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
