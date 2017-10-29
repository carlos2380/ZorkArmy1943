#include "Ncp.h"



Ncp::Ncp()
{
	ttype = NCP_TYPE;
}

Ncp::Ncp(const char* name, const char* description, int health, CretureStat stat)
: Creature(name, description, health, stat)
{
	ttype = NCP_TYPE;
}

Ncp::~Ncp()
{
}

void Ncp::Strike(int damage)
{
	Creature::Strike(damage);
	stat = ATTACKING;
}

