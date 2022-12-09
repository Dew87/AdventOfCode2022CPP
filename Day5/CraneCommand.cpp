#include "CraneCommand.h"

using namespace std;

CraneCommand::CraneCommand(int move, int from, int to) : move(move), from(from), to(to)
{}

ostream& operator << (ostream &o, const CraneCommand &craneCommand)
{
	o << "move " << craneCommand.move << " from " << craneCommand.from << " to " << craneCommand.to;
	return o;
}
