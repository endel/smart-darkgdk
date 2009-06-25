#pragma once

#include "MainMenu.h"

class PlaneFight
{
private:
	int width, height;
	MainMenu menu;
public:
	PlaneFight(void);
	~PlaneFight(void);
	void start();
	bool loop();
};
