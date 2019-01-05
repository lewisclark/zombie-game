#ifndef NCURSESWRAPPER_H
#define NCURSESWRAPPER_H

#include <ncurses.h>
#include <memory>
#include <string>
#include <exception>

namespace ncurses {
	class Window;
	//typedef WINDOW Window;

	std::unique_ptr<Window> Initialize();
	void Kill();
	void Print(std::string str);

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
