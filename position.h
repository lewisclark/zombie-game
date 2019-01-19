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


#ifndef POSITION_H
#define POSITION_H

// Used for representing a position on the screen

namespace game {
	class Position {
		public:
		Position();
		Position(const int& x, const int& y);

		const int& GetX() const;
		const int& GetY() const;
		void SetX(const int& x);
		void SetY(const int& y);

		private:
		int m_x;
		int m_y;
	};

	class Size {
		public:
		Size();
		Size(const int& w, const int& h);

		const int& GetW() const;
		const int& GetH() const;
		void SetW(const int& w);
		void SetH(const int& h);

		private:
		int m_w;
		int m_h;
	};
}

#endif
