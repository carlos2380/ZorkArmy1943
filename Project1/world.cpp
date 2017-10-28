#include "World.h"
#include "room.h"
#include "player.h"
#include <iostream>
#include "exit.h"
#include "place.h"


World::World()
{
	Place* tree = new Place("Tree", "Colgando con el paracaidas de un arbol", 0, false);
	vector<Place*> placesZoneA;
	placesZoneA.push_back(tree);
	Room* airplane = new Room("Airplain", "you are in one airplane");
	Room* zoneA = new Room("Zone A", "you are in Zone A", placesZoneA, 0);
	Exit* exit = new Exit("nord", "Big door", zoneA, "");
	Exit* exit2 = new Exit("south", "Big door", airplane, "");
	zones.push_back(airplane);
	zones.push_back(zoneA);
	airplane->AddItem(*exit);
	zoneA->AddItem(*exit2);
	player = new Player();
	player->SetRoom(*airplane);
}


World::~World()
{
}

void World::MovePlayer(vector<string>& tokens)
{
	string condition;
	bool open = true;
	Exit* exit = (Exit*) player->GetRoom()->GetEntity(tokens[1], EXIT_TYPE);
	if(exit != nullptr)
	{
		if(exit->GetCondition().compare("") != 0)
		{
			
		}

		if(open)
		{
			player->GetRoom()->ExitCreature(player->GetName());
			player->SetRoom(*(exit->GetDestination()));
			exit->GetDestination()->EnterCreature(*player);
			player->Look();
		}else
		{
			cout << "You can't GO! The " << exit->GetDescription() << " is blocked!" << endl;
		}
	}
	else cout << "You can't go to " << tokens[1] << "!" << endl;
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
		break;
		case 2: // commands with no arguments ------------------------------
		{
			if (!tokens[0].compare("go")) // Why negated¿?
			{
				MovePlayer(tokens);
			}
			else
			{
				unparseable = true;
			}
		}
		break;
		default:
			unparseable = true;
			
	}

	if(unparseable)
	{
		cout << "\nSorry, I do not understand your command.\n";
		unparseable = false;
	}
}
