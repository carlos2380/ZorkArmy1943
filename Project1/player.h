#ifndef __Player__
#define __Player__

#include "Creature.h"

class Player : public Creature
{
public:
	Player();
	~Player();

	Room* GetRoom();
	void SetRoom(Room &room);
	void Look();
	void Move(const string &place);

private:
	Room* room;
};

#endif
