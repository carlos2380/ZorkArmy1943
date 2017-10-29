#include "Ncp.h"
#include "weapond.h"
#include "Item.h"


Ncp::Ncp()
{
	ttype = NCP_TYPE;
	Weapond* pistol = new Weapond("luger pistol", "Pistol luger, simple to use", true, 2, 5, 40, "9mm");
	equip = pistol;
	for(int i = 0; i < 10; ++i)
	{
		Item* bullet = new Item("9mm", "Ammo", NORMAL);
		equip->AddItem(*bullet);
	}
}

Ncp::Ncp(const char* name, const char* description, int health, CretureStat stat)
: Creature(name, description, health, stat)
{
	ttype = NCP_TYPE;
	Weapond* pistol = new Weapond("luger pistol", "Pistol luger, simple to use", true, 2, 5, 40, "9mm");
	equip = pistol;
	for (int i = 0; i < 10; ++i)
	{
		Item* bullet = new Item("9mm", "Ammo", NORMAL);
		equip->AddItem(*bullet);
	}
}

Ncp::~Ncp()
{
}

void Ncp::Strike(int damage)
{
	Creature::Strike(damage);
	if(isAlive()) stat = ATTACKING;
}

