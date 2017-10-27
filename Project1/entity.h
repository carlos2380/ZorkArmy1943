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
	PLAYER_TYPE
};

class Entity
{
public:
	Entity();
	Entity(const char* name, const char* description);
	virtual ~Entity();
	EntityType GetType() const;

	//virtual void Update();

protected:
	string name;
	string description;
private:
	enum type;
	list<Entity*> contains;
};

#endif