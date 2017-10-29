#include "Creature.h"



Creature::Creature()
{
	ttype = CREATURE_TYPE;
	health = 100;
	alive = true;
}

Creature::Creature(const char* name, const char* description, int health, CretureStat stat) 
: Entity(name, description), health(health), stat(stat)
{
	alive = true;
	ttype = CREATURE_TYPE;
	if (health <= 0) alive = false;
}

Creature::~Creature()
{
}

bool Creature::isAlive()
{
	return alive;
}

int Creature::GetHealth()
{
	return health;
}

void Creature::Strike(int damage)
{
	health -= damage;
	if(health <= 0)
	{
		alive = false;
	}
}

bool Creature::SetEquip(Entity& entity)
{
	if(entity.GetType() == WEAPOND_TYPE)
	{
		equip = entity;
		return true;
	}
	return false;
}

Entity Creature::GetEquip()
{
	return  equip;
}


