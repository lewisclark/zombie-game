#ifndef ITEM_H
#define ITEM_H

#include "entity.h"

namespace game {
	class Item : public Entity {
		public:
		void Think();
		bool IsValid();

		private:
	};
}

#endif
