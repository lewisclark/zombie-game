#ifndef CHARACTER_H
#define CHARACTER_H

#include "entity.h"

namespace game {
	class Character : public Entity {
		public:
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
