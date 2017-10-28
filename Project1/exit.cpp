#include "Exit.h"
#include "Room.h"
#include <iostream>



Exit::Exit()
{
	ttype = EXIT_TYPE;
}

Exit::Exit(const char* name, const char* description, Room* destination, const char* condition)
: Entity(name, description), destination(destination), condition(condition)
{
	ttype = EXIT_TYPE;
}

Exit::~Exit()
{
}

Room* Exit::GetDestination()
{
	return destination;
}

string Exit::GetCondition()
{
	return condition;
}
