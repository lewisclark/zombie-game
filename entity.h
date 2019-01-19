#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "renderer.h"
#include "position.h"

namespace game {
	class Entity {
		public:
		Entity();
		Entity(std::string name);
		virtual ~Entity();

		virtual void Think();
		virtual bool IsValid() const;
		virtual void Draw(Renderer* ren) const;

		const std::string& GetName() const;
		void SetName(const std::string& name);

		const int& GetHealth() const;
		void SetHealth(const int& health);

		void Hurt(const int& damage);

		const int& GetMaxHealth() const;
		void SetMaxHealth(const int& max_health);

		Position& GetPosition();
		void SetPosition(const Position& p);

		Size& GetSize();
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
