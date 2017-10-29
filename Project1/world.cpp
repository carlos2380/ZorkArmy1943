#include "World.h"
#include "room.h"
#include "player.h"
#include "exit.h"
#include "place.h"
#include "globals.h"
#include "weapond.h"
#include "item.h"
#include "ncp.h"
#include "creature.h"
#include <iostream>


World::World()
{
	Place* tree = new Place("tree", "There are big parachute colgando de un arbol", "You are enganxado con el paracaidas colgando del arbol ", 0, false);
	Place* forest = new Place(&FOREST[0], "Alote forest", "Tou are in the Forest", 0, true);
	vector<Place*> placesZoneA;
	placesZoneA.push_back(tree);
	placesZoneA.push_back(forest);

	

	Room* airplane = new Room("Airplain", "you are in one airplane");
	Room* zoneA = new Room("Zone A", "you are in Zone A", placesZoneA, 0);
	Exit* exit = new Exit("nord", "Big door", zoneA, "");
	Exit* exit2 = new Exit("south", "Big door", airplane, "");
	zones.push_back(airplane);
	zones.push_back(zoneA);
	airplane->AddItem(*exit);
	zoneA->AddItem(*exit2);
	player = new Player("Bishop", "Coronel of SAS", 100, STANDING);
	player->SetRoom(*airplane);
	Weapond* pistol = new Weapond("pistol", "M1911 made by Colt, USA", true, 30, 50, 60, "9mm");
	Item* butllet = new Item("9mm", "Type of ammo", NORMAL);
	Item* butllet2 = new Item(*butllet);
	Ncp* enemy = new Ncp("enemy1", "Enemy!", 80, WALKING);
	airplane->EnterPlayer(*player);
	airplane->AddItem(*pistol);
	airplane->AddItem(*butllet);
	airplane->AddItem(*butllet2);
	forest->AddItem(*enemy);

	electritityActived = true;
}


World::~World()
{
}

void World::GoPlayer(vector<string>& tokens)
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
			if (!player->GetRoom()->EnemyAttacking()) {
				player->GetRoom()->ExitPlayer(player->GetName());
				player->SetRoom(*(exit->GetDestination()));
				exit->GetDestination()->EnterPlayer(*player);
				player->Look();
			}else
			{
				cout << "Enemies attacking you!" << endl;
			}
		}else
		{
			cout << "You can't GO! The " << exit->GetDescription() << " is blocked!" << endl;
		}
	}
	else cout << "You can't go to " << tokens[1] << "!" << endl;
}


bool World::ParseCommand(vector<string>& tokens)
{
	bool unparseable = false;
	switch (tokens.size())
	{
		case 1: 
		{
			if (!tokens[0].compare("look") || !tokens[0].compare("l")) 
			{
				player->Look();
			}
			else if(!tokens[0].compare("inventary") || !tokens[0].compare("i"))
			{
				player->Inventary();
			}
			else if (!tokens[0].compare("unequip"))
			{
				player->Unequip();
			}
			else if (!tokens[0].compare("stats"))
			{
				player->Creature::Stats();
			}
			else
			{
				unparseable = true;
			}
		}
		break;
		case 2: 
		{
			if (!tokens[0].compare("go")) 
			{
				GoPlayer(tokens);
			}
			else if (!tokens[0].compare("walk") || !tokens[0].compare("move") || !tokens[0].compare("run")) 
			{
				player->Move(tokens[1]);
			}
			else if (!tokens[0].compare("take"))
			{
				player->Take(tokens[1]);
			}
			else if (!tokens[0].compare("equip"))
			{
				player->Equip(tokens[1]);
			}
			else if (!tokens[0].compare("attack"))
			{
				player->Attack(tokens[1]);
			}
			else if (!tokens[0].compare("stats"))
			{
				player->Stats(tokens[1]);
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
	}
	player->GetRoom()->TurnAttackEnemies(*player);

	if(!player->isAlive())
	{
		cout << endl << "\t---- GAME OVER ----" << endl;
		return true;
	}
	return false;
}
