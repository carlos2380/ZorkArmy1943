#include "Word.h"
#include "room.h"


Word::Word()
{
	Room* airplane = new Room("Zone A", "you are in one airplane");
	zones.push_back(airplane);

}


Word::~Word()
{
}
