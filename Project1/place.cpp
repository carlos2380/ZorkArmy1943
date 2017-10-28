#include "place.h"



Place::Place()
{
	visited = false;
}

Place::Place(const char* name, const char* description, int &visibility, bool &accessible) 
: Entity(name, description), visibility(visibility), accessible(accessible)
{
	ttype = PLACE_TYPE;
	visited = false;
}

Place::~Place()
{
}
