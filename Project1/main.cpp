#include <iostream>
#include <conio.h>
#include "globals.h"
#include <vector>
#include "entity.h"
#include "Room.h"
#include "Player.h"
#include "world.h"
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
	World word;
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
			word.ParseCommand(tokens);
			tokens.clear();
			intputLine = "";
			cout << "> ";
		}
	}

	return 0;
}