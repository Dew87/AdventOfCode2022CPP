#ifndef ENTRY_H
#define ENTRY_H

#include <ostream>

struct Entry
{
	Entry(char opponent, char player);

	char opponent;
	char player;
	char shape;
};

std::ostream& operator << (std::ostream &o, const Entry &entry);

#endif
