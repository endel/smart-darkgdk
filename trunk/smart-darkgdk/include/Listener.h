#pragma once

#include "Event.h"

class Listener
{
public:
	Listener(void);
	~Listener(void);
	virtual void execute(Event* e) = 0;
};
