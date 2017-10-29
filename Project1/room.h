#ifndef __Room__
#define __Room__

#include "Entity.h"
#include <vector>

class Place;
class Player;
class Room : public Entity
{
public:
	Room();
	Room(const char* name, const char* description);
	Room(const char* name, const char* description, vector<Place*> &places, int firstPlace);
	~Room();

	void Look();
	void EnterCreature(Entity &entity);
	void ExitCreature(string &name);
	void EnterPlayer(Entity &entity);
	void ExitPlayer(string &name);
	void MovePlayer(const string &place);
	bool TakeToPlayer(const string &name, Player &player);

private:
	vector<Place*> places;
	int firstPlace;
	int currentPlayerPlace;
};

#endif

