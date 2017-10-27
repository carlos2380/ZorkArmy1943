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

protected:
	string name;
	string description;
private:
	enum type;
	list<Entity*> contains;
};

#endif