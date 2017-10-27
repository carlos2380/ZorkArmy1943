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

void Room::Look()
{
	cout << name << ", " << description << endl;
}
