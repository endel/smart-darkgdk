#pragma once

class EventDispatcher;

class Event
{
public:
	Event(char *_id,EventDispatcher *e);
	~Event(void);
public:
	EventDispatcher *target;
	char *id;
};
