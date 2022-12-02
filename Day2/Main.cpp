#include "Entry.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int EvaluateGuideNew(vector<Entry> &vInput)
{
	int sum = 0;
	for (vector<Entry>::iterator i = vInput.begin(); i != vInput.end(); i++)
	{
		int score_outcome = 0;
		switch ((*i).player)
		{
		case 'X':
			switch ((*i).opponent)
			{
			case 'A':
				(*i).shape = 'C';
				break;
			case 'B':
				(*i).shape = 'A';
				break;
			case 'C':
				(*i).shape = 'B';
				break;
			default:
				(*i).shape = 'A' - 1;
				cout << "Invalid opponent value: " << *i << "\n";
				break;
			}
			break;
		case 'Y':
			score_outcome = 3;
			switch ((*i).opponent)
			{
			case 'A':
			case 'B':
			case 'C':
				(*i).shape = (*i).opponent;
				break;
			default:
				(*i).shape = 'A' - 1;
				cout << "Invalid opponent value: " << *i << "\n";
				break;
			}
			break;
		case 'Z':
			score_outcome = 6;
			switch ((*i).opponent)
			{
			case 'A':
				(*i).shape = 'B';
				break;
			case 'B':
				(*i).shape = 'C';
				break;
			case 'C':
				(*i).shape = 'A';
				break;
			default:
				(*i).shape = 'A' - 1;
				cout << "Invalid opponent value: " << *i << "\n";
				break;
			}
			break;
		default:
			(*i).shape = 'A' - 1;
			cout << "Invalid player value: " << *i << "\n";
			break;
		}
		int score_shape = (*i).shape - 'A' + 1;
		sum += score_shape + score_outcome;
	}
	return sum;
}

int EvaluateGuideOld(const vector<Entry> &vInput)
{
	int sum = 0;
	for (vector<Entry>::const_iterator i = vInput.begin(); i != vInput.end(); i++)
	{
		int score_shape = (*i).player - 'X' + 1;
		int score_outcome = 0;
		switch ((*i).opponent)
		{
		case 'A':
			switch ((*i).player)
			{
			case 'X':
				score_outcome = 3;
				break;
			case 'Y':
				score_outcome = 6;
				break;
			default:
				break;
			}
			break;
		case 'B':
			switch ((*i).player)
			{
			case 'Y':
				score_outcome = 3;
				break;
			case 'Z':
				score_outcome = 6;
				break;
			default:
				break;
			}
			break;
		case 'C':
			switch ((*i).player)
			{
			case 'X':
				score_outcome = 6;
				break;
			case 'Z':
				score_outcome = 3;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		sum += score_shape + score_outcome;
	}
	return sum;
}

void InputGuide(vector<Entry> &vOutput)
{
	cout << "Start of guide input (A|B|C X|Y|Z Invalid input to end)\n";
	while (true)
	{
		string input;
		getline(cin, input);

		size_t i = input.find(" ");
		if (i != string::npos && i == 1 && input.size() == 3)
		{
			char a = input[0];
			char b = input[2];

			bool aValid = 'A' <= a && a <= 'C';
			bool bValid = 'X' <= b && b <= 'Z';

			if (aValid && bValid)
			{
				vOutput.push_back(Entry(a, b));
				continue;
			}
		}
		break;
	}
	cout << "End of guide input\n\n";
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

	vector<Entry> guide;

	InputGuide(guide);
	PrintVector(guide, "guide", "\n");

	int scoreOld = EvaluateGuideOld(guide);
	int scoreNew = EvaluateGuideNew(guide);

	PrintVector(guide, "extended guide with shape", "\n");

	cout << "Guide old score: " << scoreOld << "\n";
	cout << "Guide new score: " << scoreNew << "\n";

	return 0;
}
