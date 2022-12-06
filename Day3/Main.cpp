#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define LOWERCASE_PRIORITIES 1
#define UPPERCASE_PRIORITIES 27

using namespace std;

int CheckGroupBadges(const vector<string> &vInput, size_t groupSize)
{
	int sum = 0;
	if (0 < groupSize)
	{
		for (int i = 0; i + groupSize - 1 < vInput.size(); i += groupSize)
		{
			for (int j = 0; j < vInput[i].size(); j++)
			{
				char c = vInput[i][j];
				int occurences = 1;
				for (int k = i + 1; k < i + groupSize; k++)
				{
					size_t index = vInput[k].find(c);
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

int ErrorCheckRucksacks(const vector<string> &vInput)
{
	int sum = 0;
	for (int i = 0; i < vInput.size(); i++)
	{
		size_t middle = vInput[i].size() / 2;
		string inventoryA = vInput[i].substr(0, middle);
		string inventoryB = vInput[i].substr(middle);
		if (inventoryA.size() == inventoryB.size())
		{
			for (int j = 0; j < inventoryA.size(); j++)
			{
				char c = inventoryA[j];
				size_t index = inventoryB.find(c);
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

void InputRucksacks(vector<string> &vInput)
{
	cout << "Start of rucksacks input (Blank input to end)\n";
	while (true)
	{
		string input;
		getline(cin, input);
		if (input != "")
		{
			vInput.push_back(input);
			continue;
		}
		break;
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

	vector<string> rucksacks;

	InputRucksacks(rucksacks);

	PrintVector(rucksacks, "rucksacks", "\n");

	int errorCheckRucksacks = ErrorCheckRucksacks(rucksacks);
	int checkGroupBadges = CheckGroupBadges(rucksacks, number);

	cout << "Priority errors sum: " << errorCheckRucksacks << "\n";
	cout << "Priority groups of " << number << " badges sum: " << checkGroupBadges << "\n";

	return 0;
}
