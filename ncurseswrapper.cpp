#include "ncurseswrapper.h"

std::unique_ptr<ncurses::Window> ncurses::Initialize() {
	std::unique_ptr<Window> w = std::make_unique<Window>(initscr()); // Init ncurses
	if (!w->IsValid()) {
		throw std::exception();
	}

	// Make ncurses not wait for enter keypress for input and other stuff
	if (noecho() == ERR || cbreak() == ERR || keypad(stdscr, true) == ERR || curs_set(false) == ERR) {
		throw std::exception();
	}

	timeout(10);

	return w;
}

void ncurses::Kill() {
	endwin(); // Deinit ncurses
}

void ncurses::Print(std::string str) {
	printw("%s", str.c_str());
}

game::Size ncurses::GetWindowSize(Window* w) {
	game::Size size;

	int y, x;
	getmaxyx(w->Get(), y, x);

	size.SetH(y);
	size.SetW(x);

	return size;
}

void ncurses::ClearWindow(ncurses::Window* w) {
	werase(w->Get());
}

void ncurses::DrawCharacter(Window* w, const int& y, const int& x, const char& c) {
	mvwaddch(w->Get(), y, x, c);	
}

// class Window

ncurses::Window::Window(WINDOW* w) : m_window(w) {
	
}

ncurses::Window::~Window() {
	delwin(m_window);
}

WINDOW* ncurses::Window::Get() {
	return m_window;
}

bool ncurses::Window::IsValid() {
	return reinterpret_cast<long long>(m_window) != ERR;
}
