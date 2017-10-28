#include "Entity.h"



Entity::Entity()
{
	ttype = ENTITY_TYPE;
}

Entity::Entity(const char* name, const char* description) : name(name), description(description)
{
	ttype = ENTITY_TYPE;
}

Entity::~Entity()
{
}

EntityType Entity::GetType()
{
	return ttype;
}

Entity* Entity::GetEntity(const string &name, const EntityType type)
{
	for(list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if ((*it)->name.compare(name) == 0 && (*it)->GetType() == type) return *it;
	}
	return nullptr;
}

string Entity::GetName()
{
	return name;
}

string Entity::GetDescription()
{
	return description;
}

void Entity::AddItem(Entity &entity)
{
	contains.push_back(&entity);
}

bool Entity::RemoveItem(const string& name)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); ++it)
	{
		if ((*it)->name.compare(name) == 0)
		{
			contains.erase(it);
			return true;
		}
	}
	return false;
}
