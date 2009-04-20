#include "smart-darkgdk/Game.h"

void DarkGDK ( void )
{
	//-->-----------------------------------------
	//-->			INICIALIZATION
	//-->-----------------------------------------

	Game::init("Projeto Smart DarkGKK", 800, 600);
	Game::setDir("Media/");
	
	Mouse::hide();
	
	//-->-----------------------------------------
	//-->				VARIABLES
	//-->-----------------------------------------

	Matrix* matrix = new Matrix(2000,2000,20,20);
	matrix->prepareImage("Testes/grass_T.BMP");


	//Object* playerAnimado = new Object(CUBE, 20); 
	Object* playerAnimado = new Object("Testes/garota.x");
	playerAnimado->position(0,0,0);
	playerAnimado->rotate(0, 180, 0);
	playerAnimado->fixPivot();
	
	playerAnimado->addAnimation("caminha", 570, 605, 50);
	playerAnimado->addAnimation("idle", 430, 542, 50);
	
	Camera* camera = new Camera();
	
	//-->-----------------------------------------
	//-->			 LOOP PRINCIPAL
	//-->-----------------------------------------
	
	while(Game::loop())
	{
			
		playerAnimado->localMove((dbRightKey() - dbLeftKey()) * 3, 0, (dbUpKey() - dbDownKey()) * 3);

		if(dbRightKey() || dbLeftKey() || dbUpKey() || dbDownKey())
		{
			playerAnimado->playAnimation("caminha");
		}
		else
		{
			playerAnimado->playAnimation("idle");
		}

		if(dbRightKey())
		{
			//playerAnimado->rotate(0, 3, 0);
			playerAnimado->rotateY(2);
		}
		
		if(dbLeftKey())
		{
			//playerAnimado->rotate(0, -3, 0);
			playerAnimado->rotateY(-2);
		}
	
		camera->setToFollow(playerAnimado,ANGLE_Y,150,80,20,1);
		//camera->follow3DPerson(playerAnimado, 500, 370, 120); 
			
		Mouse::setPosition(Game::width()/2,Game::height()/2);

		//-->Atualiza Game
		Game::refresh();
	}

	return;
}