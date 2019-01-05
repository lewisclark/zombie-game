#ifndef GLOBALS_H
#define GLOBALS_H

namespace game {
	// Maximum amount of objects that can exist in a world instance
	const int MAX_ZOMBIES = 32;
	const int MAX_ITEMS = 12;
	const int MAX_PLAYERS = 1; // localplayer
	const int MAX_CHARACTERS = MAX_PLAYERS + MAX_ZOMBIES;
	const int MAX_ENTITIES = MAX_CHARACTERS + MAX_ITEMS;
}

#endif
