#include "Room.h"
#include <iostream>

using namespace std;

Room::Room()
{
	ttype = ROOM_TYPE;
}

Room::Room(const char* name, const char* description) : Entity(name, description)
{
	ttype = ROOM_TYPE;
}

Room::~Room()
{
}


void Room::Look()
{
	cout << name << ", " << description << endl;
}
