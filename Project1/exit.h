#include "entity.h"

class Room;
class exit : public entity
{
public:
	exit();
	~exit();

private:
	enum direction;
	Room* source;
	Room* destination;
};

