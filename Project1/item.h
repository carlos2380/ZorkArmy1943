#ifndef __Item__
#define __Item__

#include "Entity.h"


enum SpecType
{
	DAMAGE,
	ACCURACY
};

enum ItemType
{
	ACCESORY,
	NORMAL
};

class Item : public Entity
{
public:
	Item();
	Item(const char* name, const char* description, ItemType itemType);
	Item(const char* name, const char* description, ItemType itemType, SpecType spec, int value);
	~Item();

	SpecType GetSpec();
	int GetValue();

private:
	ItemType itemType;
	SpecType spec;
	int value;
};

#endif
