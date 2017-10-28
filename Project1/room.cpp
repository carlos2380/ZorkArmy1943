#include "Room.h"
#include <iostream>
#include "place.h"

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
	cout << name << ", " << description << endl;
	for (int i = 0; (i < places.size()); ++i)
	{
		cout << places[i]->GetName() << ", " << places[i]->GetDescription() << endl;
	}
	cout << endl << "You are in ";
	if (currentPlayerPlace >= 0)
	{
		cout << places[currentPlayerPlace]->GetName() << endl;
	}
	else
	{
		cout << GetName() << endl;
	}
}

void Room::EnterCreature(Entity &entity)
{
	if(firstPlace >= 0)
	{
		places[firstPlace]->AddItem(entity);
		places[firstPlace]->SetVisited(true);
		currentPlayerPlace = firstPlace;
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