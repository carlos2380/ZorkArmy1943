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
