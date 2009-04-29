#include "smart-darkgdk/Game.h"

int score = 0;

//Airplane control
float	acceleration	= 0.03,
		friction		= 0.01,
		speed			= 0,
		maxSpeed		= 2,

		gravity			= 0.005,
		flyAcceleration = 0.006,
		gravitySpeed	= 0,
		maxGravity		= 1;

void DarkGDK ( void )
{
	//Game configurations
	Game::init("Before burner 0.0000001",800,600);
	Game::setDir("Game01/Media/");

	Fog::enable(255,255,255,2000);
	
	Music *backgroundMusic = new Music("sound/Iron Maiden - Aces High.mid");
	//backgroundMusic->loop();

	Matrix *cenario = new Matrix(500,20000,10,400);
	cenario->prepareImage("textures/grass_T.BMP");

	Object *skybox = new Object(SPHERE, -2000);
	skybox->setImage("textures/sky.jpg");
	skybox->setLight(false);

	Object *jogador = new Object("models/airplane 2.x");
	jogador->rotateY(180);
	jogador->fixPivot();
	jogador->position(cenario->getWidth()/2,5,20);

	Camera* camera = new Camera();
	
	Lives *lives = new Lives("icons/live.png",3);
	
	lives->setPosition(8,6,2);

	while (Game::loop())
	{
		//Draw score
		String::draw(10,50,"Score: ");
		String::draw(66,50,score);

		if (Key::check(KEY_W))
		{
			if (speed < maxSpeed)
				speed += acceleration;
		}

		if (Key::check(KEY_S))
		{
			speed -= friction;
		}

		if (Key::check(KEY_A))
		{
			jogador->rotateY(-2);
		}
		if (Key::check(KEY_D))
		{
			jogador->rotateY(2);
		}

		//speed friction
		if (speed >= friction)
			speed -= friction;

		//let airplane to fly...
		if (speed > maxSpeed-acceleration)
		{
			String::draw(100,100,"Máxima velocidade");
			//if (gravitySpeed < maxGravity)
			if (jogador->getPositionY() < 20)
			{
				if (gravitySpeed < maxGravity)
				{
					String::draw(100,130,"Acelerando pra cima");
					gravitySpeed += flyAcceleration;
				}
			}
		}

		//player allways try to move
		jogador->move(speed);
		jogador->moveY(gravitySpeed);

		//gravitation
		if (jogador->getPositionY() > 1)
		{
			String::draw(100,160,"Caindo com gravidade...");
			if (speed > maxSpeed-acceleration)
			{
				if (gravitySpeed > gravity)
				gravitySpeed -= gravity;
			} else
			{
				gravitySpeed -= gravity;
			}
		} else 
		{
			gravitySpeed = 0;
		}
		
		skybox->position(jogador);
		camera->setToFollow(jogador,ANGLE_Y,40,10,10,1);

		Game::refresh();
	}
	return ;

}