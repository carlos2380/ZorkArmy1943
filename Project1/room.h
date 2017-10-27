#ifndef __Room__
#define __Room__

#include "Entity.h"

class Room : public Entity
{
public:
	Room();
	Room(const char* name, const char* description);
	~Room();

private:

};

#endif

