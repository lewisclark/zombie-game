#ifndef NCURSESWRAPPER_H
#define NCURSESWRAPPER_H

#include <ncurses.h>
#include <memory>
#include <string>
#include <exception>

#include "position.h"

namespace ncurses {
	class Window;
	//typedef WINDOW Window;

	std::unique_ptr<Window> Initialize();
	void Kill();
	void Print(std::string str);
	game::Size GetWindowSize(Window* w);
	void ClearWindow(Window* w);
	void DrawCharacter(Window* w, const int& y, const int& x, const char& c);

	class Window {
		public:
		Window(WINDOW* w);
		~Window();
		WINDOW* Get();
		bool IsValid();

		private:
		WINDOW* m_window;
	};
}

#endif
