#include "CrateYard.h"

using namespace std;

ostream& operator << (ostream &o, const CrateYard &crateYard)
{
	vector<stack<char>> stacks = crateYard.stacks;
	if (!stacks.empty())
	{
		size_t stackMaxSize = 0;
		for (size_t i = 0; i < stacks.size(); i++)
		{
			size_t size = stacks[i].size();
			stackMaxSize = stackMaxSize < size ? size : stackMaxSize;
		}

		// Print crate stacks [X]
		for (size_t i = stackMaxSize; 0 < i; i--)
		{
			for (size_t j = 0; j < stacks.size(); j++)
			{
				if (stacks[j].size() == i)
				{
					char c = stacks[j].top();
					stacks[j].pop();
					o << "[" << c << "] ";
				}
				else
				{
					o << "    ";
				}
			}
			o << "\n";
		}

		// Print stack numbers
		for (size_t i = 0; i < stacks.size(); i++)
		{
			o << " " << i + 1 << "  ";
		}
	}
	return o;
}
