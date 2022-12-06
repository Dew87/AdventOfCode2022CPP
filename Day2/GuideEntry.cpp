#include "GuideEntry.h"

using namespace std;

GuideEntry::GuideEntry(char opponent, char player) : opponent(opponent), player(player), shape(' ')
{}

ostream& operator << (ostream &o, const GuideEntry &entry)
{
	o << entry.opponent << ' ' << entry.player << ' ' << entry.shape;
	return o;
}
