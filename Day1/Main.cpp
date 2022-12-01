#include "Elf.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetTopElvesCarriedCalories(const vector<Elf> &vSortedInput, int number)
{
	// vSortedInput needs to be sorted in descending order
	int sum = 0;
	if (number <= vSortedInput.size())
	{
		for (int i = 0; i < number; i++)
		{
			sum += vSortedInput[i].carriedCalories;
		}
	}
	return sum;
}

void InputElvesCalories(vector<Elf> &vOutput)
{
	vector<int> backpack;
	cout << "Start of elves calories input (Numbers or separation by blank line Invalid input to end)\n";
	while (true)
	{
		string input;
		getline(cin, input);
		if (input == "")
		{
			vOutput.push_back(Elf(backpack));
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
				vOutput.push_back(Elf(backpack));
				backpack.clear();
				break;
			}
		}
	}
	cout << "End of elves calories input\n\n";
}

template <typename T>
void PrintVector(const vector<T> &vInput, const char *vName, const char* separation)
{
	cout << "Start of " << vName << "[" << vInput.size() << "] print\n";
	if (0 < vInput.size())
	{
		for (size_t i = 0; i < vInput.size() - 1; i++)
		{
			cout << vInput[i] << separation;
		}
		cout << vInput[vInput.size() - 1] << "\n";
	}
	cout << "End of " << vName << " print\n\n";
}

int main()
{
	cout << "Advent of code 2022\n";
	cout << "Day 1: Calorie Counting\n";
	cout << "Program by David Erikssen\n\n";

	int number = 3;

	vector<Elf> elves;
	vector<Elf> sortedElves;

	InputElvesCalories(elves);
	PrintVector(elves, "Elves", "\n\n");

	cout << "Sort elves by carried calories descending order\n";
	sortedElves = elves;
	sort(sortedElves.begin(), sortedElves.end(), [](Elf &a, Elf &b) { return a.carriedCalories > b.carriedCalories; });
	PrintVector(sortedElves, "Sorted elves", "\n\n");

	int topElfCarriedCalories = GetTopElvesCarriedCalories(sortedElves, 1);
	int topElvesCarriedCalories = GetTopElvesCarriedCalories(sortedElves, number);

	cout << "Top elf carried calories: " << topElfCarriedCalories << "\n";
	cout << "Top " << number << " elves carried calories : " << topElvesCarriedCalories << "\n";

	return 0;
}
