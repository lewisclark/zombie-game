#include "game.h"

game::Game::Game(/*ncurses::Window* w*/) {
	//Initialize(w);
}

void game::Game::Initialize(/*ncurses::Window* w*/) {
	//m_window = w;

	m_inputmgr = std::make_unique<InputManager>();
	m_drawmgr = std::make_unique<DrawManager>(/*w*/);

	NewGame(); // Immediately start a game for now until a menu exists
}

void game::Game::NewGame() {
	m_world = std::make_unique<World>(Size(0, 0)/*ncurses::GetWindowSize(m_window)*/);
}

void game::Game::DestroyGame() {
	m_world.reset();
}

void game::Game::Loop() {
	ProcessInput(m_inputmgr->GetStoredInput());
	Think();
	Draw();
}

void game::Game::ProcessInput(const std::vector<char>& inputs) {
	if (m_menuopen) { // or m_menu->IsOpen()
		// m_menu->ProcessInput(inputs);
	}
	else if (m_world) {
		m_world->ProcessInput(inputs);
	}

	m_inputmgr->ClearStoredInput();
}

void game::Game::Think() {
	m_world->Think();
}

void game::Game::Draw() {
	if (m_menuopen) { // or m_menu->IsOpen()
		// m_menu->Draw();
	}
	else if (m_world) {
		//m_drawmgr->DrawWorld(m_world.get());
	}
}
