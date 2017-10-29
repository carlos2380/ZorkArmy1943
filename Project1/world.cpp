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
	Place* tree = new Place("tree", "There are big parachute hanging from a tree", "Luckily the parachute got hooked on the tree!", 0, false);
	
	Place* forest = new Place("forest", "See a lot of high tree in the fores", "You are in the forest covered by trees", 0, true);
	Item* butllet = new Item("9mm", "Type of ammo", NORMAL);
	Item* butllet2 = new Item(*butllet);
	Weapond* pistol = new Weapond("pistol", "M1911 made by Colt, USA", true, 30, 50, 80, "9mm");
	forest->AddItem(*butllet);
	forest->AddItem(*butllet2);
	forest->AddItem(*pistol);

	Place* path = new Place("path", "small path in the midle of the zone A", "You are in the dirt path", 0, true);
	Item* butllet3 = new Item("5.56mm", "Type of ammo", NORMAL);
	Ncp* enemy = new Ncp("antje", "Soldier enemy", 65, WALKING);
	Ncp* enemy1 = new Ncp("berit", "Soldier enemy", 95, WALKING);
	path->AddItem(*butllet3);
	path->AddItem(*enemy);
	path->AddItem(*enemy1);

	Place* lake = new Place("lake", "a big lake in the oest of zone", "You are diving in the lake", 0, true);
	Weapond* tomahawk = new Weapond("tomahawk", "Knive like a axe", false, 35, 60, 60, "");
	lake->AddItem(*tomahawk);

	vector<Place*> placesZoneA;
	placesZoneA.push_back(tree);
	placesZoneA.push_back(forest);
	placesZoneA.push_back(path);
	placesZoneA.push_back(lake);

	Place* meadow = new Place("meadow", "a big meadow for hide", "you are lying down in the meadow", 0, true);
	Item* butllet4 = new Item(*butllet);
	Item* butllet5 = new Item(*butllet3);
	meadow->AddItem(*butllet4);
	meadow->AddItem(*butllet5);

	Place* mountain = new Place("mountain", "you see a snowed mountain at the bottom", "you are at the top of mountain, beutifull see!", 0, true);
	Ncp* enemy2 = new Ncp("alder", "Crnel enemy", 65, WALKING);
	Ncp* enemy3 = new Ncp("cort", "CGF enemy", 65, WALKING);
	Weapond* snipper = new Weapond("snipper", "Knive like a axe", true, 80, 120, 80, "");
	path->AddItem(*enemy2);
	path->AddItem(*enemy3);
	path->AddItem(*snipper);

	vector<Place*> placesZoneB;
	placesZoneB.push_back(meadow);
	placesZoneB.push_back(mountain);

	Place* entrace = new Place("entrace", "entrance with a stall house", "you are inside of hall", 0, true);
	Ncp* enemy4 = new Ncp("derek", "security enemy", 30, WALKING);
	Ncp* enemy5 = new Ncp("emil", "security enemy", 30, WALKING);
	entrace->AddItem(*enemy4);
	entrace->AddItem(*enemy5);

	Place* training = new Place("training", "you see training camp with wheels and ropes", "you are in the training camp", 0, true);
	Ncp* enemy6 = new Ncp("noa", "Crnel enemy", 50, WALKING);
	Ncp* enemy7 = new Ncp("luis", "CGF enemy", 50, WALKING);
	training->AddItem(*enemy6);
	training->AddItem(*enemy7);

	vector<Place*> placesZoneD;
	placesZoneB.push_back(entrace);
	placesZoneB.push_back(training);

	Place* camp = new Place("camp", "green camp", "you are in in the green camp", 0, true);
	Ncp* enemy8 = new Ncp("austin", "Crnel enemy", 10, WALKING);
	Item* butllet6 = new Item(*butllet);
	Item* butllet7 = new Item(*butllet3);
	Item* butllet8 = new Item(*butllet);
	Item* butllet9 = new Item(*butllet3);
	Item* butllet10 = new Item(*butllet);
	Item* butllet11 = new Item(*butllet3);
	camp->AddItem(*butllet6);
	camp->AddItem(*butllet7);
	camp->AddItem(*butllet8);
	camp->AddItem(*butllet9);
	camp->AddItem(*butllet10);
	camp->AddItem(*butllet11);
	camp->AddItem(*enemy8);

	vector<Place*> placesZoneC;
	placesZoneB.push_back(camp);

	Place* room = new Place("room", "room with the enemy and the host", "The enemy have de host and you are quite!", 0, true);
	Creature* host = new Creature("shara", "the host, you mast rescue", 50, SITTING);
	Ncp* enemy9 = new Ncp("adolf", "captain enemy", 100, WALKING);
	camp->AddItem(*enemy9);
	camp->AddItem(*host);

	vector<Place*> placesHouse;
	placesZoneB.push_back(room);

	Room* zoneA = new Room("Zone A", "The area to the south", placesZoneA, 0);
	Room* zoneB = new Room("Zone B", "The area to the east", placesZoneB, 0);
	Room* zoneC = new Room("Zone C", "The area to entrance", placesZoneC, 0);
	Room* zoneD = new Room("Zone D", "The area to west", placesZoneD, 0);
	Room* house = new Room("House", "The house of host", placesHouse, 0);
	Room* airplane = new Room("Airplane", "a big military plane");

	Exit* exitPlane = new Exit("jump", "Through the door you can see de dark sky.", zoneA, "");
	airplane->AddItem(*exitPlane);

	Exit* exitAToB = new Exit("east", "back to the forest you can see more", zoneB, "");
	Exit* exitAToD = new Exit("nord", "in front you see the entrance", zoneC, "");
	Exit* exitAToC = new Exit("nord", "behin the lake same calm", zoneD, "");
	zoneA->AddItem(*exitAToB);
	zoneA->AddItem(*exitAToD);
	zoneA->AddItem(*exitAToC);

	Exit* exitBToA = new Exit("south", "maybe is better come back or no?", zoneA, "");
	zoneB->AddItem(*exitBToA);

	Exit* exitCToA = new Exit("south", "come back to swim?", zoneA, "");
	zoneC->AddItem(*exitCToA);

	Exit* exitDToA = new Exit("south", "come back and be a coward", zoneA, "");
	Exit* exitDToHouse = new Exit("enter", "door to hause", house, "");
	house->AddItem(*exitDToA);
	house->AddItem(*exitDToHouse);

	player = new Player("Bishop", "Coronel of SAS", 100, STANDING);
	player->SetRoom(*airplane);
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
			else if (!tokens[0].compare("reload"))
			{
				player->Reload();
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
				player->GetRoom()->EnemiesSeekPlayer();
			}
			else if (!tokens[0].compare("walk") || !tokens[0].compare("move") || !tokens[0].compare("run")) 
			{
				player->Move(tokens[1]);
				player->GetRoom()->EnemiesSeekPlayer();
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
			else if (!tokens[0].compare("drop"))
			{
				player->Drop(tokens[1]);
			}
			else if (!tokens[0].compare("rescue"))
			{
				if(player->Rescue(tokens[1]))
				{
					cout << endl << "\t---- YOU WIN ----" << endl;
					return true;
				}
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
