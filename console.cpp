#include "console.h"

void GetConsoleSize(int* rows, int* columns) {
	#ifdef __linux__
		struct winsize window_size;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);

		*rows = window_size.ws_row;
		*columns = window_size.ws_col;
	#elif _WIN32

	#endif
}
