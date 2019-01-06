#include "game.h"

game::Game::Game(ncurses::Window* w) {
	Initialize(w);
}

void game::Game::Initialize(ncurses::Window* w) {
	m_window = w;

	m_inputmgr = std::make_unique<InputManager>();
	m_drawmgr = std::make_unique<DrawManager>(w);

	NewGame(); // Immediately start a game for now until a menu exists
}

void game::Game::NewGame() {
	m_world = std::make_unique<World>(ncurses::GetWindowSize(m_window));
}

void game::Game::DestroyGame() {
	m_world.reset();
}

void game::Game::Loop() {
	//ncurses::Print("Game::Loop()\n");

	//m_inputmgr->HandleInput(); // inputmgr should send movement commands to the world instance (only player related) anything else is managed elsewhere
	m_world->Think();
	m_drawmgr->DrawWorld(m_world.get());
}
