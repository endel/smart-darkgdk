#pragma once

#include "MainMenu.h"

class PlaneFight
{
private:
	MainMenu menu;
public:
	PlaneFight(void);
	~PlaneFight(void);
	void start();
	bool loop();
};
