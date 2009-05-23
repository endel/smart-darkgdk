#pragma once
#include "EventDispatcher.h"

class CommonObject 
	: public EventDispatcher
{
protected:
	void setId(int n);
public:
	int id;
	CommonObject(void);
	~CommonObject(void);
};
