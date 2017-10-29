#include "globals.h"
#include <conio.h>
#include <iostream>

using namespace std;

void UpdateInput(string &intputLine, bool &isEndLine)
{
	if (_kbhit() != 0)
	{
		char ch = _getch();
		//erase
		if (ch == '\b')
		{
			if (intputLine.length() > 0)
			{
				intputLine.pop_back();
				cout << '\b';
				cout << " ";
				cout << '\b';
			}
		}
		else if (ch != '\r') // return
		{
			intputLine += ch;
			cout << ch;
		}
		else
		{
			isEndLine = true;
			cout << endl;
		}
	}
}

void Tokenize(const string& line, vector<string>& tokens)
{
	string token = "";

	for(int i = 0; i < line[i]; ++i)
	{
		if(line[i] != ' ')
		{
			if(64 < line[i] && line[i] < 91) token += line[i] + 32;
			else token += line[i];
		}
		else 
		{
			if (token != "" && token != "to" && token != "the" && token != "in" && token != "on" && token != "at")
				tokens.push_back(token);

			token = "";
		}
	}

	if (token != "" && token != "to" && token != "the" && token != "in" && token != "on" && token != "at")
		tokens.push_back(token);

}

int RandomNumber(int min, int max)
{
	int num = rand() % (max - min);
	num += min;
	//cout << endl << "\t\t" << num << endl;
	return num;
}