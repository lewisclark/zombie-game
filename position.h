#ifndef POSITION_H
#define POSITION_H

// Used for representing a position on the screen

namespace game {
	class Position {
		public:
		Position();
		Position(int x, int y);

		int GetX();
		int GetY();
		void SetX(int x);
		void SetY(int y);

		private:
		int m_x;
		int m_y;
	};

	class Size {
		public:
		Size();
		Size(int w, int h);

		int GetW();
		int GetH();
		void SetW(int w);
		void SetH(int h);

		private:
		int m_w;
		int m_h;
	};
}

#endif
