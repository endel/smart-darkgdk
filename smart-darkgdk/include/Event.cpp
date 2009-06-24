#include "Event.h"
#include "EventDispatcher.h"

Event::Event(char* _id, EventDispatcher *e)
{
	id = _id;
	target = e;
}

Event::~Event(void)
{
}
