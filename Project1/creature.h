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
	Creature(const char* name, const char* description, int health, CretureStat stat);
	virtual ~Creature();

	bool isAlive();
	int GetHealth();
	void Strike(int damage);
	bool SetEquip(Entity &entity);
	Entity* GetEquip();
	void Stats();
	int GetDammageAttack();

protected:
	bool alive;
	int health;
	Entity* equip = nullptr;
	CretureStat stat;

private:
	Room* location;
};

#endif
