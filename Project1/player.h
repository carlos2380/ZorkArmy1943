#ifndef __Player__
#define __Player__

#include "Creature.h"

class Player : public Creature
{
public:
	Player();
	Player(const char* name, const char* description, int health, CretureStat stat);
	~Player();

	Room* GetRoom();
	void SetRoom(Room &room);
	void Look();
	void Inventary();
	void Move(const string &place);
	void Take(const string &name);
	void Unequip();
	void Equip(const string &name);
	void Attack(const string &name);
	void Stats(const string &name);
	void Reload();
private:
	Room* room;
};

#endif
