#include "Rucksack.h"

using namespace std;

Rucksack::Rucksack(string inventoryA, string inventoryB) : inventoryA(inventoryA), inventoryB(inventoryB)
{}

ostream& operator << (ostream &o, const Rucksack &rucksack)
{
	o << rucksack.inventoryA << ' ' << rucksack.inventoryB;
	return o;
}
