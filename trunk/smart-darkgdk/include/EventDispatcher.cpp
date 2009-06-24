#include "EventDispatcher.h"
#include "Event.h"
#include "Listener.h"

EventDispatcher::EventDispatcher(void)
{
}

EventDispatcher::~EventDispatcher(void)
{
}

void EventDispatcher::dispatchEvent(Event *e)
{
	listeners[e->id]->execute(e);
}

void EventDispatcher::addEventListener(char *name, Listener *l)
{
	listeners[name] = l;
}

void EventDispatcher::removeEventListener(char *name)
{
	listeners[name] = NULL;
}