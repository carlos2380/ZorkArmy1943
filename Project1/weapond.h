#ifndef __Weapond__
#define __Weapond__

#include "entity.h"


class Weapond :
	public Entity
{
public:
	Weapond();
	Weapond(const char* name, const char* description, bool remote, int minDamage, int maxDamage, int accuracy, const char* typeAmmo);
	~Weapond();

	bool IsRemote();
	int GetMinDamage();
	int GetMaxDamage();
	int GetAccuracy();
	int GetAmmo();
	string GetTypeAmmo();
	int Atack();

private:

	bool remote;
	int minDamage;
	int maxDamage;
	int accuracy;
	string typeAmmo;
};

#endif