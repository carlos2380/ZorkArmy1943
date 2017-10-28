#ifndef __Player__
#define __Player__

#include "Creature.h"

class Player : public Creature
{
public:
	Player();
	~Player();
	EntityType GetType();

	Room* GetRoom();
	void SetRoom(Room &room);
	void Look();
private:
	Room* room;
};

#endif
