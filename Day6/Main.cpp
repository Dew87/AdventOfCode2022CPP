#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

size_t IndexForFirstNumberOfDistinctCharacters(const string &input, size_t number)
{
	for (size_t i = 0; i + number - 1 < input.size(); i++)
	{
		string s = input.substr(i, number);
		sort(s.begin(), s.end());

		int duplicates = 0;
		for (size_t j = 0; j + 1 < s.size(); j++)
		{
			if (s[j] == s[j + 1])
			{
				duplicates++;
			}
		}
		if (duplicates == 0)
		{
			return i;
		}
	}
	return string::npos;
}

void InputDatastream(string &input)
{
	cout << "Start of datastream input\n";
	cin >> input;
	cout << "End of datastream input\n\n";
}

void PrintDatastream(const string &input, const char *vName)
{
	cout << "Start of " << vName << "[" << input.size() << "] print\n";
	cout << input << "\n";
	cout << "End of " << vName << " print\n\n";
}

int main()
{
	cout << "Advent of code 2022\n";
	cout << "Day 6: Tuning Trouble\n";
	cout << "Program by David Erikssen\n\n";

	size_t packetMarkerSize = 4;
	size_t messageMarkerSize = 14;

	string datastream;

	InputDatastream(datastream);
	PrintDatastream(datastream, "datastream");

	size_t packetMarkerIndex = IndexForFirstNumberOfDistinctCharacters(datastream, packetMarkerSize);
	size_t messageMarkerIndex = IndexForFirstNumberOfDistinctCharacters(datastream, messageMarkerSize);

	if (packetMarkerIndex != string::npos)
	{
		cout << "Start-of-packet marker index[" << packetMarkerIndex + packetMarkerSize << "]: " << datastream.substr(packetMarkerIndex, packetMarkerSize) << "\n";
	}
	else
	{
		cout << "No start-of-packet marker found\n";
	}

	if (messageMarkerIndex != string::npos)
	{
		cout << "Start-of-message marker index[" << messageMarkerIndex + messageMarkerSize << "]: " << datastream.substr(messageMarkerIndex, messageMarkerSize) << "\n";
	}
	else
	{
		cout << "No start-of-message marker found\n";
	}

	return 0;
}
