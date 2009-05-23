#include "smart-darkgdk/Game.h"

void DarkGDK ( void )
{
	//Game configurations
	Game::init( "Smart DarkGDK - Testing features", 800, 600 );
	Game::setDir("Media/");

	Camera *camera = new Camera();

	BSP::load("maps/20kdm2.pk3","maps/20kdm2.bsp");
	BSP::setCamera(camera);
	BSP::enableAllObjectCollisions();

	Object *player = new Object(SPHERE,1);
	player->position(50,30,50);	

	BSP::setCollisionThreshold(player, 1);

	Limb* limb = player->addLimb(new Object(CUBE, 0.2));
	limb->offset(0.3,0,0.3);

	while ( Game::loop() )
	{

		if (Key::up())
		{
			player->move(0.5);
		}
		if (Key::down())
		{
			player->move(-0.5);
		}
		if (Key::left())
		{
			player->rotateY(-0.8);
		}
		if (Key::right())
		{
			player->rotateY(0.8);
		}

		if (!BSP::getCollisionHit(player)) {
			player->moveY(-0.1);
		}

		camera->setToFollow( player, ANGLE_Y, 3, 1, 10, 1 );
		Game::refresh();
	}
	return;

}