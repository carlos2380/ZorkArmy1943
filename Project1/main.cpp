#include <iostream>
#include <conio.h>
#include "globals.h"
#include <vector>
using namespace std;

enum main_states
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};


int main() {

	int main_return = EXIT_FAILURE;
	main_states state = MAIN_CREATION;
	string intputLine;
	vector<string> tokens;
	bool isEndLine = false;

	while (state != MAIN_EXIT)
	{
		UpdateInput(intputLine, isEndLine);
		if(isEndLine)
		{
			isEndLine = false;
			Tokenize(intputLine, tokens);
			intputLine = "";
		}
	}

	return 0;
}