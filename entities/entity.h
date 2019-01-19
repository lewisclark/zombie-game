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
