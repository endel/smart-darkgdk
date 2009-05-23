#include "smart-darkgdk/Game.h"
#include <vector>

using namespace std;

int score = 0;

int PROFUNDIDADE_CENARIO = 20000;
int LARGURA_CENARIO = 500;

//Airplane control
float	acceleration	= 0.03,
		friction		= 0.01,
		speed			= 0,
		maxSpeed		= 3,

		gravity			= 0.005,
		flyAcceleration = 0.006,
		gravitySpeed	= 0,
		maxGravity		= 1;

float	rotation				= 0,
		rotationAcceleration	= 0.1,
		rotationReturning		= 0.5,
		rotationFriction		= 0.03,
		maxRotation				= 1;

float	cameraSmooth	= 10;

vector<Object*> addPoints;

void DarkGDK ( void )
{
	//Game configurations
	Game::init( "Before burner 0.0000001", 800, 600 );
	Game::setDir("Media/");

	Fog::enable( 255, 255, 255, 2500 );
	
	//game sounds
	Music *backgroundMusic = new Music("sound/Iron Maiden - Aces High.mid");
	backgroundMusic->loop();

	//create ground matrix
	Matrix *cenario = new Matrix( LARGURA_CENARIO, PROFUNDIDADE_CENARIO, 10, 400 );
	cenario->prepareTexture("textures/grass_T.BMP");

	//create walls
	int profundidade_parede_unica = 2000;
	for (int i=0;i< (int) (PROFUNDIDADE_CENARIO/profundidade_parede_unica) ;i++)
	{
		for (int j=0;j<2;j++)
		{
			//loses the pointer; don't need it in this little demo.
			Object *parede = new Object(1, 200, profundidade_parede_unica);
			parede->setPosition(LARGURA_CENARIO*j, 0, profundidade_parede_unica*i);
			parede->setTexture("textures/wall.jpg");
			parede->scaleTexture( profundidade_parede_unica/250, 1 );
			parede->setLight(false);
		}
	}
	
	//create skysphere
	Object *skysphere = new Object( SPHERE, -4000 );
	skysphere->setTexture("textures/sky.jpg");
	skysphere->setLight(false);

	//create player
	Object *jogador = new Object("models/airplane 2.x");
	jogador->rotateY(180);
	//jogador->scale(10);
	jogador->fixPivot();
	jogador->setPosition( cenario->getWidth()/2, 5, 50 );

	//Objetos
	for (int i=0;i<80;i++)
	{
		Object *temp = new Object(SPHERE, 10);
		temp->position(
			random(cenario->getWidth()-temp->getSizeX()),
			5 + random(20), 
			random(cenario->getDepth())
		);
		addPoints.push_back(temp);
	}

	Camera* camera = new Camera();
	
	Lives *lives = new Lives( "icons/live.png", 3 );
	lives->setPosition( 8, 6, 2 );

	while ( Game::loop() )
	{
		//Draw score
		String::draw(10,50,"Score: ");
		String::draw(66,50,score);
		
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
			jogador->rotateZ( rotation );
		} else {
		//no rotation --> reset rotation to zero
			if (jogador->getAngleZ() > rotationReturning)
			{
				jogador->rotateZ( -rotationReturning );
			} else if (jogador->getAngleZ() < -rotationReturning)
			{
				jogador->rotateZ( rotationReturning );
			}
		}
		
		//speed friction
		if ( speed >= friction )
			speed -= friction;

		//let airplane to fly...
		if ( speed > maxSpeed-acceleration )
		{
			if ( jogador->getPositionY() < 20 )
				if ( gravitySpeed < maxGravity )
					gravitySpeed += flyAcceleration;
		}
		
		//player allways try to move
		jogador->move( speed );
		jogador->positionY(gravitySpeed);
		jogador->positionX( -rotation );

		//restore rotation point
		if ( rotation > rotationFriction)
		{
			rotation -= rotationFriction;
		} else if ( rotation < -rotationFriction )
		{
			rotation += rotationFriction;
		}

		//gravitation
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
		}

		//collision detection
		vector<Object*>::iterator it = addPoints.begin();
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
		}
		
		skysphere->setPosition( jogador );
		camera->setToFollow( jogador, ANGLE_Y, 40, 10, cameraSmooth, 1 );

		Game::refresh();
	}
	return ;

}