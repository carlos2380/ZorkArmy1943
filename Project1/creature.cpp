#include "Creature.h"
#include "weapond.h"
#include <iostream>
#include "globals.h"


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

CretureStat Creature::GetStat()
{
	return stat;
}

void Creature::SetStat(CretureStat cretureStat)
{
	stat = cretureStat;
}

void Creature::Strike(int damage)
{
	health -= damage;
	if(health <= 0)
	{
		alive = false;
		stat = DEAD;
	}
}

bool Creature::SetEquip(Entity& entity)
{
	if(entity.GetType() == WEAPOND_TYPE)
	{
		equip = &entity;
		return true;
	}
	return false;
}

Entity* Creature::GetEquip()
{
	if(equip == nullptr) return nullptr;
	else return equip;
}

void Creature::Stats()
{
	if(isAlive())
	{
		cout << "Stats of " << GetName() <<":" << endl;
		cout << "\tHealth: " << health << " points." << endl;
		if (equip == nullptr)
		{
			cout << "\tEquip: No equip." << endl;
			cout << "\tAccuracy: " << 80 << "%" << endl;
			cout << "\tDamage: " << "20 - 30 points" << endl;
		}
		else
		{
			cout << "\tEquip: " << equip->GetName() << "." << endl;
			cout << "\tAccuracy: " << ((Weapond*)equip)->GetAccuracy() << "%" << endl;
			cout << "\tDamage: " << ((Weapond*)equip)->GetMinDamage() << " - " << ((Weapond*)equip)->GetMaxDamage() << " points" << endl;
		}
	}else
	{
		cout << GetName() << " is dead!" << endl;
	}
}

int Creature::GetDammageAttack()
{
	if (equip == nullptr)
	{
		if (RandomNumber(1, 100) <= 20) return 0;
		else
		{
			return RandomNumber(20, 30);
		}
	}
	else
	{
	
		if (RandomNumber(1, 100) <= ((Weapond*)equip)->GetAccuracy()) return 0;
		else
		{
			RandomNumber(((Weapond*)equip)->GetMinDamage(), ((Weapond*)equip)->GetMaxDamage());
		}
	}
}
