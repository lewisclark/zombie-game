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
