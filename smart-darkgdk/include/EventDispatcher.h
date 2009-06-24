#pragma once
#include <map>

class Event;
class Listener;

class EventDispatcher
{
public:
	EventDispatcher(void);
	~EventDispatcher(void);
protected://functions
	void dispatchEvent(Event *e);

public: 
	void addEventListener(char *name, Listener *l);
	void removeEventListener(char *name);

protected://variables
	std::map<char*, Listener *> listeners;
};