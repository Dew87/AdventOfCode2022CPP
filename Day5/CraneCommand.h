#ifndef CRANE_COMMAND_H
#define CRANE_COMMAND_H

#include <ostream>

struct CraneCommand
{
	CraneCommand(int move, int from, int to);

	int move;
	int from;
	int to;
};

std::ostream& operator << (std::ostream &o, const CraneCommand &craneCommand);

#endif
