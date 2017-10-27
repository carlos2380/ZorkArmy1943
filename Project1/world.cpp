#include "World.h"
#include "room.h"
#include "player.h"
#include <iostream>


World::World()
{
	Room* airplane = new Room("Airplain", "you are in one airplane");
	Room* zoneA = new Room("Zone A", "you are in one airplane");
	zones.push_back(airplane);
	zones.push_back(zoneA);
	player = new Player();
	player->SetRoom(*airplane);

}


World::~World()
{
}

void World::ParseCommand(vector<string>& tokens)
{
	bool unparseable = false;
	switch (tokens.size())
	{
		case 1: // commands with no arguments ------------------------------
		{
			if (!tokens[0].compare("look") || !tokens[0].compare("l")) // Why negated¿?
			{
				player->Look();
			}
			else
			{
				unparseable = true;
			}
		}
	}

	if(unparseable)
	{
		cout << "\nSorry, I do not understand your command.\n";
	}
}
