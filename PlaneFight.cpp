#include "PlaneFight.h"
#include "MainMenu.h"
#include "smart-darkgdk/Game.h"

PlaneFight::PlaneFight(void)
{
}

PlaneFight::~PlaneFight(void)
{
}

void PlaneFight::start()
{
	menu.start();
}

bool PlaneFight::loop()
{
	if (menu.active())
	{
		
	}

	return Game::loop();
}