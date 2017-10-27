#ifndef __World__
#define __World__

#include<vector>
using namespace std;

class Entity;
class Player;
class World
{
public:
	World();
	~World();
	void ParseCommand(vector<string>& tokens);
private:
	vector<Entity*> zones;
	Player* player = nullptr;
};

#endif
