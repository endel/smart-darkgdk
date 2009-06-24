#include "smart-darkgdk/Game.h"
#include "PlaneFight.h"

void DarkGDK ( void )
{
	PlaneFight game;
	game.start();

	while (game.loop())
	{
		Game::refresh();
	}
	return ;
}