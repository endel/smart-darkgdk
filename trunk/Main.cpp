#include "smart-darkgdk/Game.h"

void DarkGDK ( void )
{
	//Game configurations
	Game::init( "Before burner 0.0000001", 800, 600 );
	Game::setDir("Game01/Media/");

	Object *player = new Object(CUBE,20);
	Matrix *matrix = new Matrix(1000,1000,20,20);
	
	Limb* limb = player->addLimb(new Object(CUBE, 10));
	limb->offset(20,0,20);

	Camera *camera = new Camera();

	while ( Game::loop() )
	{

		if (Key::up())
		{
			player->move(2);
		}
		if (Key::down())
		{
			player->move(-2);
		}
		if (Key::left())
		{
			player->rotateY(-0.5);
		}
		if (Key::right())
		{
			player->rotateY(0.5);
		}

		camera->setToFollow( player, ANGLE_Y, 40, 10, 10, 1 );
		Game::refresh();
	}
	return ;

}