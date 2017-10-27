#include "Entity.h"



Entity::Entity()
{
}

Entity::Entity(const char* name, const char* description) : name(name), description(description)
{
}

Entity::~Entity()
{
}

EntityType Entity::GetType() const
{
	return ENTITY_TYPE;
}
