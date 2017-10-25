#include<string>
#include <list>
using namespace std;

class entity
{
public:
	entity();
	virtual ~entity();

	//virtual void Update();

private:
	enum type;
	string name;
	string description;
	list<entity*> contains;
};

