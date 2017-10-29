#include "place.h"
#include "player.h"
#include <iostream>


Place::Place()
{
	visited = false;
}

Place::Place(const char* name, const char* description, const char* descriptionPlayer, int visibility, bool accessible)
: Entity(name, description), descriptionPlayer(descriptionPlayer), visibility(visibility), accessible(accessible)
{
	ttype = PLACE_TYPE;
	visited = false;
}

Place::~Place()
{
}

bool Place::IsVisited()
{
	return visibility;
}

void Place::SetVisited(bool visited)
{
	this->visited = visited;
}

int Place::GetVisibility()
{
	return visibility;
}

bool Place::IsAccessible()
{
	return accessible;
}

void Place::SetAccessible(bool accessible)
{
	this->accessible = accessible;
}

string Place::GetDesciptionPlayer()
{
	return descriptionPlayer;
}

void Place::Look()
{
	if(visited)
	{
		for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
		{
			if ((*it)->GetType() == ITEM_TYPE || (*it)->GetType() == WEAPOND_TYPE || (*it)->GetType() == NCP_TYPE) {
				cout << "\t" << (*it)->GetName() << ": " << (*it)->GetDescription() << endl;
			}
		}
	}else
	{
		for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
		{
			if ((*it)->GetType() == NCP_TYPE) {
				cout << "\t" << (*it)->GetName() << ": " << (*it)->GetDescription() << endl;
			}
		}
	}
}

bool Place::TakeToPlayer(const string& name, Player &player)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (!(*it)->GetName().compare(name) && ((*it)->GetType() == ITEM_TYPE || (*it)->GetType() == WEAPOND_TYPE)) {
			player.AddItem(*(*it));
			contains.remove(*it);
			return true;
		}
	}
	return false;
}


