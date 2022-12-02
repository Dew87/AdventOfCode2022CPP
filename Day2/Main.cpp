#include "Entry.h"
#include <iostream>
#include <string>
#include <vector>

#define DRAW_OUTCOME 0
#define DRAW_SCORE 3
#define LOSS_OUTCOME -1
#define LOSS_SCORE 0
#define WIN_OUTCOME 1
#define WIN_SCORE 6

using namespace std;

const int DIFFERENCE_OPPONENT_PLAYER = 'A' - 'X';
const int DIFFERENCE_OUTCOME_PLAYER = DRAW_OUTCOME - 'Y';

int EvaluateGuideNew(vector<Entry> &vInput)
{
	int sum = 0;
	for (vector<Entry>::iterator i = vInput.begin(); i != vInput.end(); i++)
	{
		int outcome = (*i).player + DIFFERENCE_OUTCOME_PLAYER;

		// Calculate player shape depending on outcome. Wrap around if out of bounds
		char shape = (*i).opponent + outcome;
		shape = shape == 'A' - 1 ? 'C' : shape;
		shape = shape == 'C' + 1 ? 'A' : shape;

		// Save shape to guide
		(*i).shape = shape;

		// Calculate score for outcome, 0 loss, 3 draw, 6 win
		int score_outcome = LOSS_SCORE;
		score_outcome = outcome == WIN_OUTCOME ? WIN_SCORE : score_outcome;
		score_outcome = outcome == DRAW_OUTCOME ? DRAW_SCORE : score_outcome;

		// Calculate score for shape, 1 rock, 2 paper, 3 scissors
		int score_shape = shape - 'A' + 1;

		sum += score_shape + score_outcome;
	}
	return sum;
}

int EvaluateGuideOld(const vector<Entry> &vInput)
{
	int sum = 0;
	for (vector<Entry>::const_iterator i = vInput.begin(); i != vInput.end(); i++)
	{
		char opponent = (*i).opponent;
		char player = (*i).player + DIFFERENCE_OPPONENT_PLAYER;

		// Calculate outcome to -1 loss, 0 draw, 1 win. Wrap around if out of bounds
		int outcome = player - opponent;
		outcome = outcome == 2 ? LOSS_OUTCOME : outcome;
		outcome = outcome == -2 ? WIN_OUTCOME : outcome;

		// Calculate score for outcome, 0 loss, 3 draw, 6 win
		int score_outcome = LOSS_SCORE;
		score_outcome = outcome == WIN_OUTCOME ? WIN_SCORE : score_outcome;
		score_outcome = outcome == DRAW_OUTCOME ? DRAW_SCORE : score_outcome;

		// Calculate score for shape, 1 rock, 2 paper, 3 scissors
		int score_shape = player - 'A' + 1;

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
