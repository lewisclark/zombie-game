#ifndef COLOR_H
#define COLOR_H

#include <cinttypes>

namespace game {
	class Color {
		public:
		Color();
		Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a);
		Color(std::uint8_t r, std::uint8_t g, std::uint8_t b);

		std::uint8_t GetR();
		std::uint8_t GetG();
		std::uint8_t GetB();
		std::uint8_t GetA();

		private:
		std::uint8_t m_r;
		std::uint8_t m_g;
		std::uint8_t m_b;
		std::uint8_t m_a;
	};
}

#endif
