
#include "weapond.h"
#include "globals.h"
#include "item.h"


Weapond::Weapond()
{
	ttype = WEAPOND_TYPE;
}

Weapond::Weapond(const char* name, const char* description, bool remote, int minDamage, int maxDamage, int accuracy, const char* typeAmmo)
	: Entity(name, description), remote(remote), minDamage(minDamage), maxDamage(maxDamage), accuracy(accuracy), typeAmmo(typeAmmo)
{
	ttype = WEAPOND_TYPE;
}

Weapond::~Weapond()
{
}

bool Weapond::IsRemote()
{
	return remote;
}

int Weapond::GetMinDamage()
{
	return minDamage;
}

int Weapond::GetMaxDamage()
{
	return  maxDamage;
}

int Weapond::GetAccuracy()
{
	int accur = accuracy;

	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (!(*it)->GetType() == ITEM_TYPE)
		{
			Item* item = (Item*)*it;
			if (item->GetSpec() == ACCURACY)
			{
				accur += item->GetValue();
			}
		}
	}
	return accur;
}

int Weapond::GetAmmo()
{
	int counter = 0;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (!(*it)->GetName().compare(typeAmmo)) ++counter;
	}
	return counter;
}

string Weapond::GetTypeAmmo()
{
	return typeAmmo;
}

int Weapond::Atack()
{
	if(remote)
	{
		if(GetAmmo())
		{
			RemoveItem(GetTypeAmmo());
		}else
		{
			return -1;
		}
	}
	int damage =  RandomNumber(minDamage, maxDamage);

	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if (!(*it)->GetType() == ITEM_TYPE)
		{
			Item* item = (Item*)*it;
			if(item->GetSpec() == DAMAGE)
			{
				damage += item->GetValue();
			}
		}
	}
	return damage;
}
