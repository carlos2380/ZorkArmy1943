#ifndef __Entity__
#define __Entity__

#include<string>
#include <list>
using namespace std;

enum EntityType
{
	ENTITY_TYPE,
	ROOM_TYPE,
	EXIT_TYPE,
	PLAYER_TYPE,
	PLACE_TYPE,
	ITEM_TYPE,
	WEAPOND_TYPE,
	CREATURE_TYPE,
	NCP_TYPE
};

class Entity
{
public:
	Entity();
	Entity(const char* name, const char* description);
	virtual ~Entity();
	EntityType GetType();

	Entity* GetEntity(const string &name, const EntityType type);
	string GetName();
	string GetDescription();
	//virtual void Update();

	void AddItem(Entity &entity);
	bool RemoveItem(const string &name);

protected:
	string name;
	string description;
	EntityType ttype;
	list<Entity*> contains;
};

#endif