#ifndef __Place__
#define __Place__

#include "entity.h"
class Place :
	public Entity
{
public:
	Place();
	~Place();
	Place(const char* name, const char* description, int &visibility, bool &accessible);

	bool IsVisited();
	bool SetVisited(bool visited);
	int GetVisibility();
	bool isAccessible();

private:
	bool visited;
	int visibility;
	bool accessible;
};

#endif
