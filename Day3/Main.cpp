#include "Rucksack.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define LOWERCASE_PRIORITIES 1
#define UPPERCASE_PRIORITIES 27

using namespace std;

int CheckGroupBadges(const vector<Rucksack> &vInput, size_t groupSize)
{
	int sum = 0;
	if (0 < groupSize)
	{
		for (int i = 0; i + groupSize - 1 < vInput.size(); i += groupSize)
		{
			size_t sizeA = vInput[i].inventoryA.size();
			size_t sizeB = vInput[i].inventoryB.size();
			for (int j = 0; j < sizeA + sizeB; j++)
			{
				char c = j < sizeA ? vInput[i].inventoryA[j] : vInput[i].inventoryB[j - sizeA];
				int occurences = 1;
				for (int k = i + 1; k < i + groupSize; k++)
				{
					size_t indexA = vInput[k].inventoryA.find(c);
					size_t indexB = vInput[k].inventoryB.find(c);

					size_t index = string::npos;
					index = indexA != string::npos ? indexA : index;
					index = indexB != string::npos ? indexB : index;
					if (index != string::npos)
					{
						occurences++;
					}
				}
				if (occurences == groupSize)
				{
					if ('a' <= c && c <= 'z')
					{
						int priority = c - 'a' + LOWERCASE_PRIORITIES;
						sum += priority;
						break;
					}
					else if ('A' <= c && c <= 'Z')
					{
						int priority = c - 'A' + UPPERCASE_PRIORITIES;
						sum += priority;
						break;
					}
				}
			}
		}
	}
	return sum;
}

int ErrorCheckRucksacks(const vector<Rucksack> &vInput)
{
	int sum = 0;
	for (int i = 0; i < vInput.size(); i++)
	{
		Rucksack rucksack = vInput[i];
		if (rucksack.inventoryA.size() == rucksack.inventoryB.size())
		{
			for (int j = 0; j < rucksack.inventoryA.size(); j++)
			{
				char c = rucksack.inventoryA[j];
				size_t index = rucksack.inventoryB.find(c);
				if (index != string::npos)
				{
					if ('a' <= c && c <= 'z')
					{
						int priority = c - 'a' + LOWERCASE_PRIORITIES;
						sum += priority;
						break;
					}
					else if ('A' <= c && c <= 'Z')
					{
						int priority = c - 'A' + UPPERCASE_PRIORITIES;
						sum += priority;
						break;
					}
				}
			}
		}
	}
	return sum;
}

void InputRucksacks(vector<Rucksack> &vInput)
{
	cout << "Start of rucksacks input (Blank input to end)\n";
	while (true)
	{
		string input;
		getline(cin, input);
		if (input == "")
		{
			break;
		}
		size_t i = input.size() / 2;
		string inputA = input.substr(0, i);
		string inputB = input.substr(i);
		vInput.push_back(Rucksack(inputA, inputB));
	}
	cout << "End of rucksacks input\n\n";
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
	cout << "Day 2: Rock Paper Scissors\n";
	cout << "Program by David Erikssen\n\n";

	int number = 3;

	vector<Rucksack> rucksacks;

	InputRucksacks(rucksacks);

	PrintVector(rucksacks, "rucksacks", "\n");

	int errorCheckRucksacks = ErrorCheckRucksacks(rucksacks);
	int checkGroupBadges = CheckGroupBadges(rucksacks, number);

	cout << "Priority errors sum: " << errorCheckRucksacks << "\n";
	cout << "Priority groups of " << number << " badges sum: " << checkGroupBadges << "\n";

	return 0;
}
