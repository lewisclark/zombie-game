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


#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "../renderer.h"
#include "../position.h"
#include "../inputmanager.h"

namespace game {
	class Entity {
		public:
		Entity();
		Entity(std::string name);
		virtual ~Entity();

		virtual void Think(const InputManager* const inputmgr);
		virtual bool IsValid() const;
		virtual void Draw(Renderer* ren);

		const std::string& GetName() const;
		void SetName(const std::string& name);

		const int& GetHealth() const;
		void SetHealth(const int& health);

		void Hurt(const int& damage);

		const int& GetMaxHealth() const;
		void SetMaxHealth(const int& max_health);

		const Position& GetPosition() const;
		void SetPosition(const Position& p);

		const Size& GetSize() const;
		void SetSize(const Size& s);

		private:
		std::string m_name = "<entity>";
		int m_health = 100;
		int m_max_health = 100;
		Position m_position;
		Size m_size;
	};
}

#endif
