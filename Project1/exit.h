#ifndef __Exit__
#define __Exit__


#include "Entity.h"

class Room;
class Exit : public Entity
{
public:
	Exit();
	Exit(const char* name, const char* description, Room* destination, const char* condition);
	~Exit();

	Room* GetDestination();
	string GetCondition();
private:
	//Room* source;
	Room* destination = nullptr;
	string condition = "";

};

#endif
