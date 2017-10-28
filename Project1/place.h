#ifndef __Place__
#define __Place__

#include "entity.h"
class Place :
	public Entity
{
public:
	Place();
	~Place();
	Place(const char* name, const char* description, int visibility, bool accessible);

	bool IsVisited();
	void SetVisited(bool visited);
	int GetVisibility();
	bool IsAccessible();
	void SetAccessible(bool accessible);

private:
	bool visited;
	int visibility;
	bool accessible;
};

#endif
