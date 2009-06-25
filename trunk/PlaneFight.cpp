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
	exploding = false;

	//init vars
	PROFUNDIDADE_CENARIO = 35000;
	LARGURA_CENARIO = 900;

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
	
	initY = 120.0;

	//load contents
	Game::setDir("Media/");
	skysphere = new Object( SPHERE, -4000 );
	skysphere->setLight(false);
	skysphere->setTexture("textures/sky_grayscale.jpg");
	
	jogador = new Object(CUBE, 1);
	jogadorSprite = new Object("models/aviao.x");
	baseEnemy = new Object("models/Fokker/Fokker2.X");
	baseEnemy->scale(7);

	baseBullet = new Object(ObjectType::SPHERE, 0.5);
	baseBullet->setColor(0,0,0);

	jogadorSprite->addAnimation("Voaaa",0,101,10,LOOP);

	lives = new Lives( "icons/live.png", 3 );5
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
	baseBullet->hide();
}

void PlaneFight::startGame()
{
	cenario = new Matrix( LARGURA_CENARIO, PROFUNDIDADE_CENARIO, (int) LARGURA_CENARIO/50, (int) PROFUNDIDADE_CENARIO/50 );
	cenario->randomize(40);
	cenario->prepareTexture("textures/grass_grayscale.bmp");
	cenario->update();
	
	Fog::enable( 255, 255, 255, 2500 );

	new_enemy_interval = 300;
	new_enemy_count = 0;
	
	//game sounds
	jogadorSprite->scale(5);
	jogadorSprite->fixPivot();
	jogador->setPosition( LARGURA_CENARIO/2 , initY, 50 );
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
	//Draw score
	String::draw(10,36,"Score: ");
	String::draw(66,36,score);
	
	if (Key::check(KEY_SPACE))
	{
		if (bullets.size() < 50)
		{
			createBullet();
		}
	}

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

	if (new_enemy_count > new_enemy_interval)
	{
		new_enemy_count = 0;
		createEnemy();
	}
	new_enemy_count++;

	vector<Object*>::iterator it = enemies.begin();
	while (it != enemies.end())
	{
		bool inc_it = true;
		Object* enemy = (*it);
		if (enemy->exists())
		{
			if (enemy->collision(jogador))
			{
				explodePlayer();
			}
			
			if (enemy->getPositionZ() < jogador->getPositionZ() - 100)
			{
				it = enemies.erase(it);
				delete enemy;
				inc_it = false;
			}
		}
		if (inc_it)
			it++;
	}
	
	vector<Object*>::iterator it_bullets = bullets.begin();
	while (it_bullets != bullets.end())
	{
		bool inc_it = true;
		bool deleteEnemy = false;
		
		Object* bullet = (*it_bullets);

		if (bullet->exists())
		{
			bullet->move(20);

			Object *bullet_collision = bullet->collision();
			
			/*if (bullet_collision->exists() && (bullet_collision->id != jogador->id))
			{
				bullet_collision->setVar("life", bullet_collision->getVar("life") - 1 );
				deleteEnemy = (bullet_collision->getVar("life") <= 0);
			}*/

			if ((bullet->getPositionZ() > jogador->getPositionZ() + 1000) || deleteEnemy)
			{
				it_bullets = bullets.erase(it_bullets);
				delete bullet;
				inc_it = false;
			}

		}
		if (inc_it)
			it_bullets++;

	}

	skysphere->setPosition( jogador );
	jogadorSprite->setPosition( jogador );
	camera->follow3DPerson(jogador, 100, 30, 130);
}

void PlaneFight::createEnemy()
{
	Object* newEnemy = baseEnemy->clone();
	newEnemy->setVar("life",5);
	newEnemy->setPosition(
		100 + random(LARGURA_CENARIO-200), 
		initY, 
		jogador->getPositionZ() + 1800 + random(100) 
	);

	newEnemy->show();

	enemies.push_back(newEnemy);
}

void PlaneFight::createBullet()
{
	Object* newBullet = baseBullet->clone();
	
	newBullet->setPosition(jogador);
	newBullet->show();
	
	bullets.push_back(newBullet);
}

void PlaneFight::explodePlayer()
{
	if (!exploding)
	{
		exploding = true;
	}
}