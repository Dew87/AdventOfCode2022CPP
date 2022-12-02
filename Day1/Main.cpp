#include "Elf.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ClearElvesVector(vector<Elf*> &vInput)
{
	for (vector<Elf*>::iterator i = vInput.begin(); i != vInput.end(); i++)
	{
		delete *i;
	}
	vInput.clear();
}

int GetTopElvesCarriedCalories(vector<Elf*> &vSortedInput, int number)
{
	// vSortedInput needs to be sorted in descending order
	int sum = 0;
	if (number <= vSortedInput.size())
	{
		for (size_t i = 0; i < number; i++)
		{
			sum += vSortedInput[i]->carriedCalories;
		}
	}
	return sum;
}

void InputElvesCalories(vector<Elf*> &vOutput)
{
	vector<int> backpack;
	cout << "Start of elves calories input (Numbers or separation by blank line Invalid input to end)\n";
	while (true)
	{
		string input;
		getline(cin, input);
		if (input == "")
		{
			vOutput.push_back(new Elf(backpack));
			backpack.clear();
		}
		else
		{
			try
			{
				int i = stoi(input);
				backpack.push_back(i);
			}
			catch (exception e)
			{
				vOutput.push_back(new Elf(backpack));
				backpack.clear();
				break;
			}
		}
	}
	cout << "End of elves calories input\n\n";
}

template <typename T>
void PrintVector(const vector<T*> &vInput, const char *vName, const char *separation)
{
	cout << "Start of " << vName << "[" << vInput.size() << "] print\n";
	if (0 < vInput.size())
	{
		for (size_t i = 0; i < vInput.size() - 1; i++)
		{
			cout << *vInput[i] << separation;
		}
		cout << *vInput[vInput.size() - 1] << "\n";
	}
	cout << "End of " << vName << " print\n\n";
}

int main()
{
	cout << "Advent of code 2022\n";
	cout << "Day 1: Calorie Counting\n";
	cout << "Program by David Erikssen\n\n";

	int number = 3;

	vector<Elf*> elves;

	InputElvesCalories(elves);
	PrintVector(elves, "Elves", "\n\n");

	cout << "Sort elves by carried calories descending order\n";
	sort(elves.begin(), elves.end(), [](Elf *a, Elf *b) { return a->carriedCalories > b->carriedCalories; });
	PrintVector(elves, "Sorted elves", "\n\n");

	int topElfCarriedCalories = GetTopElvesCarriedCalories(elves, 1);
	int topElvesCarriedCalories = GetTopElvesCarriedCalories(elves, number);

	cout << "Top elf carried calories: " << topElfCarriedCalories << "\n";
	cout << "Top " << number << " elves carried calories : " << topElvesCarriedCalories << "\n";

	ClearElvesVector(elves);

	return 0;
}
