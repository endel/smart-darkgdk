#include "PlaneFight.h"
#include "MainMenu.h"
#include "PlaneFightDefs.h"
#include "smart-darkgdk/Game.h"

PlaneFight::PlaneFight(void)
{
}

PlaneFight::~PlaneFight(void)
{
}

void PlaneFight::start()
{
	width = 800;
	height = 600;

	Game::init("Plane Fight",width,height);
	Game::setDir("Media/PlaneFight/");
	Game::setBackdropColor(255,255,255);
	Sprite *loading = new Sprite("loading.png");
	loading->position( (width/2)-(loading->getWidth()/2), (height/2)-(loading->getHeight()/2) );
	Game::refresh();

	//carrega todos os modelos
	

	//fim dos carregamentos
	Game::setBackdropColor(0,0,0);
	delete loading;

	menu.start();
}

bool PlaneFight::loop()
{
	bool looping = Game::loop();

	if (!menu.active())
	{
		switch (menu.getItemSelected())
		{
			case START:
			break;
			case RECORDS:
			break;
			case CREDITS:
			break;
			case QUIT:
				looping = false;
			break;
		}


	}
	
	return looping;
}