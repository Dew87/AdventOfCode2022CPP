#include "CleanupPairs.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int FullyContainedCleanupPairs(const vector<CleanupPairs> &vInput)
{
	int sum = 0;
	for (size_t i = 0; i < vInput.size(); i++)
	{
		bool aFullyContainsB = vInput[i].aBegin <= vInput[i].bBegin && vInput[i].bEnd <= vInput[i].aEnd;
		bool bFullyContainsA = vInput[i].bBegin <= vInput[i].aBegin && vInput[i].aEnd <= vInput[i].bEnd;
		if (aFullyContainsB || bFullyContainsA)
		{
			sum++;
		}
	}
	return sum;
}

void InputCleanupPairs(vector<CleanupPairs> &vInput)
{
	cout << "Start of cleanup pairs input (X-X,X-X Invalid input to end)\n";
	while (true)
	{
		string input;
		getline(cin, input);
		size_t index = input.find(',');
		if (index != string::npos)
		{
			string a = input.substr(0, index);
			string b = input.substr(index + 1);
			size_t indexA = a.find('-');
			size_t indexB = b.find('-');
			if (indexA != string::npos && indexB != string::npos)
			{
				try
				{
					int aBegin = stoi(a.substr(0, indexA));
					int aEnd = stoi(a.substr(indexA + 1));
					int bBegin = stoi(b.substr(0, indexB));
					int bEnd = stoi(b.substr(indexB + 1));
					vInput.push_back(CleanupPairs(aBegin, aEnd, bBegin, bEnd));
					continue;
				}
				catch (exception e)
				{ }
			}
		}
		break;
	}
	cout << "End of cleanup pairs input\n\n";
}

int OverlappingCleanupPairs(const vector<CleanupPairs> &vInput)
{
	int sum = 0;
	for (size_t i = 0; i < vInput.size(); i++)
	{
		// original : if (Not(no overlap)), removed double negation so => if (overlap)
		if (vInput[i].aBegin <= vInput[i].bEnd && vInput[i].bBegin <= vInput[i].aEnd)
		{
			sum++;
		}
	}
	return sum;
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
	cout << "Day 4: Camp Cleanup\n";
	cout << "Program by David Erikssen\n\n";

	vector<CleanupPairs> cleanupPairs;

	InputCleanupPairs(cleanupPairs);

	PrintVector(cleanupPairs, "cleanup pairs", "\n");

	int fullyContainedCleanupPairs = FullyContainedCleanupPairs(cleanupPairs);
	int overlappingCleanupPairs = OverlappingCleanupPairs(cleanupPairs);

	cout << "Fully contained cleanup pairs: " << fullyContainedCleanupPairs << "\n";
	cout << "Overlapping cleanup pairs: " << overlappingCleanupPairs << "\n";

	return 0;
}
