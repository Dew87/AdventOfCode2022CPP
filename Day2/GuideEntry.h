#ifndef GUIDE_ENTRY_H
#define GUIDE_ENTRY_H

#include <ostream>

struct GuideEntry
{
	GuideEntry(char opponent, char player);

	char opponent;
	char player;
	char shape;
};

std::ostream& operator << (std::ostream &o, const GuideEntry &entry);

#endif
