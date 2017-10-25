#ifndef __NCP__
#define __NCP__

#include "Creature.h"

class Ncp : public Creature
{
public:
	Ncp();
	~Ncp();

private:
	enum st_step;
};

#endif

