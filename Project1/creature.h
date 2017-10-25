#ifndef __Creature__
#define __Creature__

#include "Entity.h"

class Room;
class Creature : public Entity
{
public:
	Creature();
	virtual ~Creature();

private:
	Room* location;
};

#endif
