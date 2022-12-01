#ifndef ELF_H
#define ELF_H

#include <ostream>
#include <vector>

struct Elf
{
	Elf(std::vector<int> backpack);
	void CalculateCarriedCalories();

	int carriedCalories;
	std::vector<int> backpack;
};

std::ostream& operator << (std::ostream &o, const Elf &elf);

#endif
