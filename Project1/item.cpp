#include "Item.h"



Item::Item()
{
	ttype = ITEM_TYPE;
}

Item::Item(const char* name, const char* description, ItemType itemType) : Entity(name, description), itemType(itemType)
{
	ttype = ITEM_TYPE;
}

Item::Item(const char* name, const char* description, ItemType itemType, SpecType spec, int value)
	: Entity(name, description), itemType(itemType), spec(spec), value(value)
{
	ttype = ITEM_TYPE;
}

Item::~Item()
{
}

SpecType Item::GetSpec()
{
	return spec;
}

int Item::GetValue()
{
	return value;
}
