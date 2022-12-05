#ifndef RUCKSACK_H
#define RUCKSACK_H

#include <ostream>
#include <string>

struct Rucksack
{
	Rucksack(std::string inventoryA, std::string inventoryB);

	std::string inventoryA;
	std::string inventoryB;
};

std::ostream& operator << (std::ostream &o, const Rucksack &rucksack);

#endif
