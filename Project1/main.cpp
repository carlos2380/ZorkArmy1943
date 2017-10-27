#include <iostream>
#include <conio.h>
#include "globals.h"
#include <vector>
#include "entity.h"
#include "Room.h"
#include "Player.h"
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

	/*vector<Entity*> detodo;
	Room* a = new Room();
	Player* p = new Player();
	detodo.push_back(a);
	detodo.push_back(p);*/
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