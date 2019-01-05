#include "game.h"

game::Game::Game(ncurses::Window* w) {
	Initialize(w);
}

void game::Game::Initialize(ncurses::Window*) {
	m_inputmgr = std::make_unique<InputManager>();
	m_drawmgr = std::make_unique<DrawManager>();

	NewGame(); // Immediately start a game for now until a menu exists
}

void game::Game::NewGame() {
	m_world = std::make_unique<World>();
}

void game::Game::DestroyGame() {
	m_world.reset();
}

void game::Game::Loop() {
	//ncurses::Print("Game::Loop()\n");
	//int con_rows, con_columns;
	//GetConsoleSize(&con_rows, &con_columns);

	//m_inputmgr->HandleInput(); // inputmgr should send movement commands to the world instance (only player related) anything else is managed elsewhere
	m_world->Think();
	m_drawmgr->DrawWorld(m_world.get());
}
