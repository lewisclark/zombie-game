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


#include "game.h"

game::Game::Game(Renderer* ren) {
	Initialize(ren);
}

void game::Game::Initialize(Renderer* ren) {
	m_renderer = ren;

	m_inputmgr = std::make_unique<InputManager>();
	m_drawmgr = std::make_unique<DrawManager>(ren);

	NewGame(); // Immediately start a game for now until a menu exists
}

void game::Game::NewGame() {
	m_world = std::make_unique<World>(m_renderer->GetCanvasSize());
}

void game::Game::DestroyGame() {
	m_world.reset();
}

void game::Game::Loop() {
	m_inputmgr->Loop();
	m_world->Think(m_inputmgr.get());
	
	if (m_menuopen) { // or m_menu->IsOpen()
		// m_menu->Draw();
	}
	else if (m_world) {
		m_drawmgr->DrawWorld(m_world.get());
	}
}

bool game::Game::ShouldQuit() {
	return m_inputmgr->IsQuitPolled();
}
