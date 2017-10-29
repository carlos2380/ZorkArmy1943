#ifndef __NCP__
#define __NCP__

#include "Creature.h"

class Ncp : public Creature
{
public:
	Ncp();
	Ncp(const char* name, const char* description, int health, CretureStat stat);
	~Ncp();

private:
	enum st_step;
};

#endif

