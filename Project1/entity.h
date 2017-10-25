#ifndef __Entity__
#define __Entity__

#include<string>
#include <list>
using namespace std;

class Entity
{
public:
	Entity();
	Entity(const char* name, const char* description);
	virtual ~Entity();
	//virtual void Update();

private:
	enum type;
	string name;
	string description;
	list<Entity*> contains;
};

#endif