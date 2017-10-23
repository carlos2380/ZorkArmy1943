#include "entity.h"

class room;
class creature : public entity
{
public:
	creature();
	virtual ~creature();

private:
	room* location;
};

