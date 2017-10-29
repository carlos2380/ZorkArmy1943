#include "Room.h"
#include "Player.h"
#include <iostream>
#include "place.h"
#include "Item.h"

using namespace std;

Room::Room()
{
	ttype = ROOM_TYPE;
}

Room::Room(const char* name, const char* description) : Entity(name, description)
{
	ttype = ROOM_TYPE;
	firstPlace = -1;
	currentPlayerPlace = -1;
}

Room::Room(const char* name, const char* description, vector<Place*> &places, int firstPlace) : Entity(name, description)
{
	ttype = ROOM_TYPE;
	this->places = places;
	if (&firstPlace != nullptr) {
		if (firstPlace < places.size())
		{
			this->firstPlace = firstPlace;
		}
		else
		{
			firstPlace = -1;
			currentPlayerPlace = -1;
		}
	}
}

Room::~Room()
{
}


void Room::Look()
{
	cout << endl << name << ", " << description << endl;
	
	for (int i = 0; (i < places.size()); ++i)
	{
		cout << places[i]->GetName() << ", " << places[i]->GetDescription() << endl;
	}

	cout << endl << "There are: " << endl;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if ((*it)->GetType() == ITEM_TYPE || (*it)->GetType() == WEAPOND_TYPE || (*it)->GetType() == NCP_TYPE) {
			cout << "\t" << (*it)->GetName() << ": " << (*it)->GetDescription() << endl;
		}
	}
	for (int i = 0; (i < places.size()); ++i)
	{
		places[i]->Look();
	}

	cout << endl << "You can go to: " << endl;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if ((*it)->GetType() == EXIT_TYPE) {
			cout << "\t" << (*it)->GetName() << ": " << (*it)->GetDescription() << endl;
		}
	}

	if (currentPlayerPlace >= 0)
	{
		cout << endl << places[currentPlayerPlace]->GetDesciptionPlayer() << endl;
	}
	else
	{
		cout << endl << "You are in " << GetName() << endl;
	}
	cout << endl;
}

void Room::EnterCreature(Entity &entity)
{
	if(firstPlace >= 0)
	{
		places[firstPlace]->AddItem(entity);
	}else
	{
		AddItem(entity);
	}
}

void Room::ExitCreature(string &name)
{
	if(!RemoveItem(name))
	{
		bool deleted = false;
		for(int i = 0; (i < places.size()) && (!deleted); ++i)
		{
			deleted = places[i]->RemoveItem(name);
		}
	}
}

void Room::EnterPlayer(Entity& entity)
{
	if (firstPlace >= 0)
	{
		currentPlayerPlace = firstPlace;
		places[firstPlace]->SetVisited(true);
	}
	else
	{
		currentPlayerPlace = -1;
	}
	AddItem(entity);
}

void Room::ExitPlayer(string& name)
{
	RemoveItem(name);
}

void Room::MovePlayer(const string& place)
{
	bool found = false;
	for (int i = 0; (i < places.size()) && (!found); ++i)
	{
		if(!places[i]->GetName().compare(place))
		{
			if(places[i]->IsAccessible())
			{
				currentPlayerPlace = i;
				cout << places[i]->GetDesciptionPlayer() << endl;
			}else
			{
				cout << "You can't move to " << place << "!" << endl;
			}
			found = true;
		}
	}
	if(!found)
	{
		cout << "Not exist place called " << place << "!" << endl;
	}
}

bool Room::TakeToPlayer(const string& name, Player &player)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (!(*it)->GetName().compare(name) && ((*it)->GetType() == ITEM_TYPE || (*it)->GetType() == WEAPOND_TYPE)) {
			player.AddItem(*(*it));
			contains.remove(*it);
			return true;
		}
	}
	for (int i = 0; (i < places.size()); ++i)
	{
		if(places[i]->IsVisited())
		{
			if(places[i]->TakeToPlayer(name, player)) {
				return true;
			}
		}
	}
	return false;
}

