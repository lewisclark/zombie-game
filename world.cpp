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


#include "world.h"

game::World::World(const Size& world_size) :
	m_world_size(world_size) {

	Initialize();
}

void game::World::Initialize() {
	m_entfactory = std::make_unique<EntityFactory>(m_world_size);

	Player* localplayer = m_entfactory->CreatePlayer();
	localplayer->SetPosition(Position(m_world_size.GetW() / 2, m_world_size.GetH() / 2));

	for (int i = 0; i < MAX_ZOMBIES; i++) {
		m_entfactory->CreateZombie(true);
	}
}

// TODO: Remove invalid entities
void game::World::Think(const InputManager* const inputmgr) {
	m_entfactory->PurgeInvalidEntities();

	for (Entity* e : m_entfactory->GetEntities()) {
		if (e && e->IsValid()) {
			e->Think(inputmgr);
		}
	}
}

game::EntityFactory* game::World::GetEntityFactory() {
	return m_entfactory.get();
}
