#include "smart-darkgdk/Game.h"

enum	PLAYER_STATE {JUMPING, FALLING, STANDBY};

float	gravity = 0,
		gravityMax = 1.5,
		gravityAcceleration = 0.01,
		
		jumpAcceleration = 0.1,
		jumpMax = 2;

PLAYER_STATE playerState = FALLING;

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
	
	while ( Game::loop() )
	{
		if (Key::up())
		{
			player->move(0.1);
		}
		if (Key::down())
		{
			player->move(-0.1);
		}
		if (Key::left())
		{
			player->rotateY(-0.5);
		}
		if (Key::right())
		{
			player->rotateY(0.5);
		}
		if (Key::check(KEY_SPACE) && playerState == STANDBY)
		{
			playerState = JUMPING;
		}

		if (!BSP::getCollisionHit(player)) {
			switch (playerState)
			{
				case FALLING:
					if (gravity > (-gravityMax)+gravityAcceleration)
						gravity -= gravityAcceleration;
				break;
				case JUMPING:
					if (gravity < jumpMax-jumpAcceleration)
					{
						gravity += jumpAcceleration;
					} else 
					{
						playerState = FALLING;
					}
				break;
				case STANDBY:
					playerState = FALLING;
				break;
			}
		} else {
			gravity = 0;
			playerState = STANDBY;
		}

		player->moveY(gravity);
		
		camera->position(player->getPositionX(), player->getPositionY() + 1.5 ,player->getPositionZ() - 1);
		camera->setRotation(player);
		
		Game::refresh();
	}
	return;

}