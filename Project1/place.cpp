#include "place.h"



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

