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
	Game::setDir("Media/");

	Game::setBackdropColor(255,255,255);

	Sprite *loading = new Sprite("PlaneFight/loading.png");
	//loading->position( (width/2)-(loading->getWidth()/2), (height/2)-(loading->getHeight()/2) );
	loading->position( 0, 0 );
	Game::loop();
	Game::refresh();

	//carrega todos os modelos
	backgroundMusic = new Music("sound/Track.mid");
	menu.load();
	loadGame();
	//fim dos carregamentos
	delete loading;

	Game::setBackdropColor(0,0,0);
	backgroundMusic->loop();

	menu.start();
}

void PlaneFight::loadGame()
{
	gameRunning = false;

	//init vars
	PROFUNDIDADE_CENARIO = 25000;
	LARGURA_CENARIO = 800;

	score = 0;

	//Airplane control
	acceleration	= 0.03;
	friction		= 0.01;
	speed			= 5;
	maxSpeed		= 15;
	bonusSpeed		= 10;

	gravity			= 0.005;
	flyAcceleration = 0.006;
	gravitySpeed	= 0;
	maxGravity		= 1;

	rotation				= 0;
	rotationAcceleration	= 0.1;
	rotationReturning		= 0.7;
	rotationFriction		= 0.03;
	maxRotation				= 1;

	cameraSmooth	= 10;


	//load contents
	Game::setDir("Media/");
	skysphere = new Object( SPHERE, -4000 );
	skysphere->setLight(false);
	skysphere->setTexture("textures/sky_grayscale.jpg");
	
	jogador = new Object(CUBE, 1);
	jogadorSprite = new Object("models/aviao.x");
	baseEnemy = new Object("models/Fokker/Fokker.X");
	jogadorSprite->addAnimation("Voaaa",0,101,10,LOOP);

	lives = new Lives( "icons/live.png", 3 );
	hideGameObjs();
}

void PlaneFight::hideGameObjs()
{
	//cenario
	skysphere->hide();
	jogador->hide();
	jogadorSprite->hide();
	lives->hide();
	baseEnemy->hide();
}

void PlaneFight::startGame()
{
	cenario = new Matrix( LARGURA_CENARIO, PROFUNDIDADE_CENARIO, (int) LARGURA_CENARIO/50, (int) PROFUNDIDADE_CENARIO/50 );
	cenario->randomize(40);
	cenario->prepareTexture("textures/grass_grayscale.bmp");
	cenario->update();
	
	Fog::enable( 255, 255, 255, 2500 );

	new_enemy_interval = 200;
	new_enemy_count = 0;
	
	//game sounds
	jogadorSprite->scale(5);
	jogadorSprite->fixPivot();
	jogador->setPosition( LARGURA_CENARIO/2 , 120, 50 );
	jogadorSprite->setPosition( jogador );

	camera = new Camera();
	
	lives->setPosition( 8, 6, 2 );

	skysphere->show();
	jogadorSprite->show();
	lives->show();
}

bool PlaneFight::loop()
{
	bool looping = Game::loop();

	if (!menu.active())
	{
		switch (menu.getItemSelected())
		{
			case START:
				if (!gameRunning) {
					startGame();
					gameRunning = true;
				}
				gameLoop();
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


void PlaneFight::gameLoop()
{

	//create player
	
	//jogador->rotateY(180);
	
	/*jogador->playAnimation("Voaaa");
	jogador->isLooping();*/

	//Objetos
	/*for (int i=0;i<80;i++)
	{
		temp = new Object(SPHERE, 10);
		temp->position(
			random(cenario->getWidth()-temp->getSizeX()),
			5 + random(20), 
			random(cenario->getDepth())
		);
		addPoints.push_back(temp);
	}*/


	//Draw score
	String::draw(10,36,"Score: ");
	String::draw(66,36,score);

	/*
	Mouse::setPosition(400, 300);
	Mouse::hide();
	
	if ( Key::check(KEY_W) )
	{
		if (speed < maxSpeed)
			speed += acceleration;
	}

		if (jogador->getPositionY() < 40)
		jogador->positionY((float)Mouse::moveY()/300);

	String::draw(200,50,(float)Mouse::moveY()/30);
	*/


	
	//up key
	if ( Key::check(KEY_W) )
	{
		if (speed < maxSpeed)
			speed += acceleration;
	}
	
	//down key
	if ( Key::check(KEY_S) )
	{
		speed -= friction;
	}
	
	//left key
	if ( Key::check(KEY_A) )
	{
		if (rotation < maxRotation-rotationAcceleration)
			rotation += rotationAcceleration;
	}
	
	//right key
	if ( Key::check(KEY_D) )
	{
		if (rotation > -(maxRotation-rotationAcceleration))
			rotation -= rotationAcceleration;
	}
	
	//left or right key --> rotate player 
	if (Key::check(KEY_A) || Key::check(KEY_D))
	{
		jogadorSprite->rotateZ( rotation );
	} else {
	//no rotation --> reset rotation to zero
		if (jogadorSprite->getAngleZ() > rotationReturning)
		{
			jogadorSprite->rotateZ( -rotationReturning );
		} else if (jogadorSprite->getAngleZ() < -rotationReturning)
		{
			jogadorSprite->rotateZ( rotationReturning );
		}
	}
	
	//speed friction
	if ( speed >= bonusSpeed )
		speed -= friction;

	//let airplane to fly...
	/*if ( speed > maxSpeed-acceleration )
	{
		if ( jogador->getPositionY() < 200 )
			if ( gravitySpeed < maxGravity )
				gravitySpeed += flyAcceleration;
	}*/
	
	//player allways try to move
	jogador->move( speed );
	jogador->positionY(gravitySpeed);
	jogador->positionX( -(rotation*2) );

	//restore rotation point
	if ( rotation > rotationFriction)
	{
		rotation -= rotationFriction;
	} else if ( rotation < -rotationFriction )
	{
		rotation += rotationFriction;
	}

	/*//gravitation
	if ( jogador->getPositionY() > 1 )
	{
		if ( speed > maxSpeed-acceleration )
		{
			if ( gravitySpeed > gravity )
				gravitySpeed -= gravity;
		} else
		{
			gravitySpeed -= gravity;
		}
	} else 
	{
		gravitySpeed = 0;
	}*/

	//collision detection
	/*vector<Object*>::iterator it = addPoints.begin();
	while (it != addPoints.end())
	{
		Object* obj1 = (*it);
		Object* obj2 = obj1->collision();
		it++;
		// se colidiu com o jogador
		if (obj2->id == jogador->id)
		{
			score++;
			delete obj1;
		}
	}*/
	

	/*float fix_dist_from_player = (cenario->getPositionZ() + (PROFUNDIDADE_CENARIO / 2)) + jogadorSprite->getSizeZ();
	if ( jogador->getPositionZ() > fix_dist_from_player ) {
		cenario->setPositionZ( jogador->getPositionZ() - (PROFUNDIDADE_CENARIO / 2) );
	}*/
	

	if (new_enemy_count > new_enemy_interval)
	{
		new_enemy_count = 0;
		//createEnemy();
		//criar inimigo

	}
	new_enemy_count++;

	vector<Object*>::iterator it;
	it = enemies.begin();
	while (it != enemies.end())
	{
		Object* enemy = (*it);
		enemy->move(-0.1);
		if (enemy->getPositionZ() < jogador->getPositionZ() - 100)
		{
			delete enemy;
		}
	}

	skysphere->setPosition( jogador );
	jogadorSprite->setPosition( jogador );
	camera->setToFollow( jogador, ANGLE_Y, 40, 10, cameraSmooth, 1 );

}

void PlaneFight::createEnemy()
{
	//Object* newEnemy = baseEnemy->clone();
	Object* newEnemy = new Object("models/Fokker/Fokker.X");

	newEnemy->position(
		100+random(LARGURA_CENARIO-200), 
		100+random(40), 
		jogador->getPositionZ() + 500 + random(100) 
	);
	enemies.push_back(newEnemy);
}