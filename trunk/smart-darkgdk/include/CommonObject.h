#pragma once
#include "EventDispatcher.h"
#include "Listener.h"

class CommonObject 
	: public EventDispatcher
{
protected:
	void setId(int n);
public:
	bool operator==(const CommonObject *c) const;
	int id;
	CommonObject(void);
	~CommonObject(void);
};
