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
