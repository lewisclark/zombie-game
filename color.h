#ifndef COLOR_H
#define COLOR_H

#include <cinttypes>

namespace game {
	class Color {
		public:
		Color();
		Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a);
		Color(std::uint8_t r, std::uint8_t g, std::uint8_t b);

		std::uint8_t GetR() const;
		std::uint8_t GetG() const;
		std::uint8_t GetB() const;
		std::uint8_t GetA() const;

		private:
		std::uint8_t m_r;
		std::uint8_t m_g;
		std::uint8_t m_b;
		std::uint8_t m_a;
	};
}

#endif
