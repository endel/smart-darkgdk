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
	width = 800;
	height = 600;

	Game::init("Plane Fight",width,height);
	Game::setDir("Media/PlaneFight/");
	Game::setBackdropColor(255,255,255);
	Sprite *loading = new Sprite("loading.png");
	loading->position( (width/2)-(loading->getWidth()/2), (height/2)-(loading->getHeight()/2) );

	//carrega todos os modelos
	

	//fim dos carregamentos
	Game::setBackdropColor(0,0,0);
	delete loading;

	menu.start();
}

bool PlaneFight::loop()
{
	if (!menu.active())
	{
		//faz o jogo rodar... (pouca coisa, detalhe)


	}
	
	return Game::loop();
}