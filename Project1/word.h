#include<vector>
using namespace std;

class entity;
class word
{
public:
	word();
	~word();

private:
	vector<entity*> entities;
};

