#ifndef CRATE_YARD_H
#define CRATE_YARD_H

#include <ostream>
#include <vector>
#include <stack>

struct CrateYard
{
	std::vector<std::stack<char>> stacks;
};

std::ostream& operator << (std::ostream &o, const CrateYard &crateYard);

#endif
