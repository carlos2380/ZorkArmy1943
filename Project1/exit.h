#ifndef __Exit__
#define __Exit__


#include "Entity.h"

class Room;
class Exit : public Entity
{
public:
	Exit();
	~Exit();

private:
	enum direction;
	Room* source;
	Room* destination;
};

#endif
