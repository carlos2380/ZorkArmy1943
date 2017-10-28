#ifndef __Creature__
#define __Creature__

#include "Entity.h"

enum CretureStat
{
	WALKING,
	CROUCHING,
	SITTING,
	SMOKING,
	STANDING,
	ATTACKING
};

class Room;
class Creature : public Entity
{
public:
	Creature();
	virtual ~Creature();

protected:
	bool live;
	int health;
	Entity equip;

private:
	Room* location;
};

#endif
