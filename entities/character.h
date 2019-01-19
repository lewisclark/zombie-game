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


#ifndef CHARACTER_H
#define CHARACTER_H

#include "entity.h"

namespace game {
	class Character : public Entity {
		public:
		Character();
		virtual ~Character();

		virtual void Think(const InputManager* const inputmgr);
		virtual bool IsValid() const;

		const int& GetStrength() const;
		const int& GetDefence() const;
		const int& GetSpeed() const;

		void SetStrength(const int& strength);
		void SetDefence(const int& defence);
		void SetSpeed(const int& speed);

		private:
		int m_strength = 1;
		int m_defence = 1;
		int m_speed = 1;
	};
}

#endif
