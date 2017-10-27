#include "Room.h"
#include <iostream>

using namespace std;

Room::Room()
{
}

Room::Room(const char* name, const char* description) : Entity(name, description)
{
}


Room::~Room()
{
}

EntityType Entity::GetType() const
{
	return ROOM_TYPE;
}

void Room::Look()
{
	cout << name << ", " << description << endl;
}
