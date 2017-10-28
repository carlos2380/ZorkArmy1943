#ifndef __Creature__
#define __Creature__

#include "Entity.h"

class Room;
class Creature : public Entity
{
public:
	Creature();
	virtual ~Creature();

protected:
	bool live;
	int health;
	int shield;
	Entity equip;

private:
	Room* location;
};

#endif
