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


#include "drawmanager.h"

game::DrawManager::DrawManager(Renderer* ren) :
	m_renderer(ren) {

}

void game::DrawManager::DrawWorld(World* world) {
	m_renderer->SetDrawColor(42, 42, 42, 255);
	m_renderer->Clear();

	DrawEntities(world->GetEntityFactory()->GetEntities());

	m_renderer->Present();
}

void game::DrawManager::DrawEntities(const std::vector<Entity*>& entities) {
	for (Entity* e : entities) {
		if (e && e->IsValid()) {
			e->Draw(m_renderer);
		}
	}
}
