#ifndef __Exit__
#define __Exit__


#include "Entity.h"

class Room;
class Exit : public Entity
{
public:
	Exit();
	~Exit();
	EntityType GetType();
private:
	enum direction;
	Room* source;
	Room* destination;
};

#endif
