#include "CraneCommand.h"
#include "CrateYard.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string CheckYardTopCrates(const CrateYard &crateYard)
{
	string output = "";
	for (size_t i = 0; i < crateYard.stacks.size(); i++)
	{
		if (!crateYard.stacks[i].empty())
		{
			output += crateYard.stacks[i].top();
		}
	}
	return output;
}

void ExecuteCommandsCrateMover9000(CrateYard &crateYard, const vector<CraneCommand> &commands)
{
	size_t size = crateYard.stacks.size();
	for (size_t i = 0; i < commands.size(); i++)
	{
		// Read command
		int move = commands[i].move;
		int from = commands[i].from - 1;
		int to = commands[i].to - 1;

		// Check if command is out of bounds
		if (0 <= from && from < size && 0 <= to && to < size)
		{
			for (size_t j = 0; j < move && !crateYard.stacks[from].empty(); j++)
			{
				char c = crateYard.stacks[from].top();
				crateYard.stacks[from].pop();
				crateYard.stacks[to].push(c);
			}
		}
	}
}

void ExecuteCommandsCrateMover9001(CrateYard &crateYard, const vector<CraneCommand> &commands)
{
	size_t size = crateYard.stacks.size();
	for (size_t i = 0; i < commands.size(); i++)
	{
		// TODO: remove temp storage, change CrateYard.stacks from type stack to vector
		stack<char> temp;

		// Read command
		int move = commands[i].move;
		int from = commands[i].from - 1;
		int to = commands[i].to - 1;

		// Check if command is out of bounds
		if (0 <= from && from < size && 0 <= to && to < size)
		{
			for (size_t j = 0; j < move && !crateYard.stacks[from].empty(); j++)
			{
				char c = crateYard.stacks[from].top();
				crateYard.stacks[from].pop();
				temp.push(c);
			}
			while (!temp.empty())
			{
				char c = temp.top();
				temp.pop();
				crateYard.stacks[to].push(c);
			}
		}
	}
}

void InputCraneCommands(vector<CraneCommand> &vInput)
{
	cout << "Start of crane entries input (move X from X to X Invalid input to end)\n";
	while (true)
	{
		string input;
		getline(cin, input);

		size_t indexMove = input.find("move");
		size_t indexFrom = input.find("from");
		size_t indexTo = input.find("to");
		if (indexMove < indexFrom && indexFrom < indexTo)
		{
			string inputMove = input.substr(indexMove + 4, input.size() - indexFrom);
			string inputFrom = input.substr(indexFrom + 4, input.size() - indexTo);
			string inputTo = input.substr(indexTo + 2);
			try
			{
				int move = stoi(inputMove);
				int from = stoi(inputFrom);
				int to = stoi(inputTo);
				vInput.push_back(CraneCommand(move, from, to));
				continue;
			}
			catch (exception e)
			{ }
		}
		break;
	}
	cout << "End of crane entries input\n\n";
}

void InputCrateYard(CrateYard &vInput)
{
	vector<vector<char>> stacksInput;
	cout << "Start of crate yard input ([X] [X]... Blank input to end)\n";
	while (true)
	{
		string input;
		getline(cin, input);

		if (input != "")
		{
			size_t index = input.find("[");
			if (index != string::npos)
			{
				for (int i = 0, j = 1; j < input.size(); i++, j += 4)
				{
					char c = input[j];
					if (c != ' ')
					{
						while (stacksInput.size() < i + 1)
						{
							stacksInput.push_back(vector<char>());
						}
						stacksInput[i].push_back(c);
					}
				}
			}
		}
		else
		{
			break;
		}
	}
	while (vInput.stacks.size() < stacksInput.size())
	{
		vInput.stacks.push_back(stack<char>());
	}
	for (size_t i = 0; i < stacksInput.size(); i++)
	{
		reverse(stacksInput[i].begin(), stacksInput[i].end());
		for (size_t j = 0; j < stacksInput[i].size(); j++)
		{
			vInput.stacks[i].push(stacksInput[i][j]);
		}
	}
	cout << "End of crate yard input\n\n";
}

void PrintCrateYard(const CrateYard &crateYard, const char *vName)
{
	cout << "Start of " << vName << " print\n";
	if (0 < crateYard.stacks.size())
	{
		cout << crateYard << "\n";
	}
	cout << "End of " << vName << " print\n\n";
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
	cout << "Day 5: Supply Stacks\n";
	cout << "Program by David Erikssen\n\n";

	CrateYard crateYardCrateMover9000;
	CrateYard crateYardCrateMover9001;
	vector<CraneCommand> craneCommands;

	InputCrateYard(crateYardCrateMover9000);
	InputCraneCommands(craneCommands);

	PrintCrateYard(crateYardCrateMover9000, "crate yard");
	PrintVector(craneCommands, "crane commands", "\n");

	crateYardCrateMover9001 = crateYardCrateMover9000;

	ExecuteCommandsCrateMover9000(crateYardCrateMover9000, craneCommands);
	PrintCrateYard(crateYardCrateMover9000, "rearranged crate yard CrateMover 9000");

	ExecuteCommandsCrateMover9001(crateYardCrateMover9001, craneCommands);
	PrintCrateYard(crateYardCrateMover9001, "rearranged crate yard CrateMover 9001");

	string crateYardCrateMover9000Top = CheckYardTopCrates(crateYardCrateMover9000);
	string crateYardCrateMover9001Top = CheckYardTopCrates(crateYardCrateMover9001);

	cout << "Top crates in rearranged yard CrateMover 9000: " << crateYardCrateMover9000Top << "\n";
	cout << "Top crates in rearranged yard CrateMover 9001: " << crateYardCrateMover9001Top << "\n";

	return 0;
}
