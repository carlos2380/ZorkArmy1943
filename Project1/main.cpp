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
	cout << "> ";
	while (state != MAIN_EXIT)
	{
		UpdateInput(intputLine, isEndLine);
		if(isEndLine)
		{
			isEndLine = false;
			Tokenize(intputLine, tokens);
			if(word.ParseCommand(tokens)) state = MAIN_EXIT;
			tokens.clear();
			intputLine = "";
			cout << "> ";
		}
	}
	system("PAUSE");
	return 0;
}