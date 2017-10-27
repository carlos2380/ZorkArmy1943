#ifndef __World__
#define __World__

#include<vector>
using namespace std;

class Entity;
class Word
{
public:
	Word();
	~Word();

private:
	vector<Entity*> zones;
};

#endif
