#ifndef CONSOLE_H
#define CONSOLE_H

#ifdef __linux__
	#include <sys/ioctl.h>
	#include <stdio.h>
	#include <unistd.h>
#elif _WIN32

#endif

#include "position.h"

extern void GetConsoleSize(int* rows, int* columns);

#endif
