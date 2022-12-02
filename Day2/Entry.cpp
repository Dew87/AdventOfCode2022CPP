#include "Entry.h"

using namespace std;

Entry::Entry(char opponent, char player) : opponent(opponent), player(player), shape(' ')
{}

ostream& operator << (ostream &o, const Entry &entry)
{
	o << entry.opponent << ' ' << entry.player << ' ' << entry.shape;
	return o;
}
