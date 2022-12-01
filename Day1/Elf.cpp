#include "Elf.h"

using namespace std;

Elf::Elf(vector<int> backpack) : backpack(backpack)
{
	CalculateCarriedCalories();
}

void Elf::CalculateCarriedCalories()
{
	int sum = 0;
	for (int i = 0; i < backpack.size(); i++)
	{
		sum += backpack[i];
	}
	carriedCalories = sum;
}

std::ostream& operator << (std::ostream &o, const Elf &elf)
{
	if (0 < elf.backpack.size())
	{
		for (int i = 0; i < elf.backpack.size() - 1; i++)
		{
			o << elf.backpack[i] << "\n";
		}
		o << elf.backpack[elf.backpack.size() - 1];
	}
	return o;
}
