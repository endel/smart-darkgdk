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
		maxSpeed		= 10,

		gravity			= 0.005,
		flyAcceleration = 0.006,
		gravitySpeed	= 0,
		maxGravity		= 1;

float	rotation				= 0,
		rotationAcceleration	= 0.1,
		rotationFriction		= 0.03,
		maxRotation				= 1;

float	cameraSmooth	= 10;

vector<Object*> addPoints;

void DarkGDK ( void )
{
	//Game configurations
	Game::init( "Before burner 0.0000001", 800, 600 );
	Game::setDir("Game01/Media/");

	Fog::enable( 255, 255, 255, 2500 );
	
	//game sounds
	Music *backgroundMusic = new Music("sound/Iron Maiden - Aces High.mid");
	//backgroundMusic->loop();

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
			parede->position(LARGURA_CENARIO*j, 0, profundidade_parede_unica*i);
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
	jogador->position(jogador->getSizeX()/2,jogador->getSizeY()/2,jogador->getSizeZ()/2);
	jogador->fixPivot();
	jogador->position( cenario->getWidth()/2, 5, 50 );
	jogador->setSmoothing(50);

	//Objetos
	for (int i=0;i<500;i++)
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

		if ( Key::check(KEY_W) )
		{
			if (speed < maxSpeed)
				speed += acceleration;
		}

		if ( Key::check(KEY_S) )
		{
			speed -= friction;
		}

		if ( Key::check(KEY_A) )
		{
			if (rotation < maxRotation-rotationAcceleration)
			{
				rotation += rotationAcceleration;
				//jogador->moveX(-rotation);
			}
		}
		if ( Key::check(KEY_D) )
		{
			if (rotation > -(maxRotation-rotationAcceleration))
			{
				rotation -= rotationAcceleration;
				//jogador->moveX(-rotation);
			}
		}

		//speed friction
		if ( speed >= friction )
			speed -= friction;

		//let airplane to fly...
		if ( speed > maxSpeed-acceleration )
		{
			String::draw(100,100,"Máxima velocidade");
			//if (gravitySpeed < maxGravity)
			if ( jogador->getPositionY() < 20 )
			{
				if ( gravitySpeed < maxGravity )
				{
					String::draw(100,130,"Acelerando pra cima");
					gravitySpeed += flyAcceleration;
				}
			}
		}
		
		//player allways try to move
		jogador->move( speed );
		jogador->moveY( gravitySpeed );
		jogador->rotateZ( rotation );

		//restore rotation point
		if ( rotation > rotationFriction )
		{
			rotation -= rotationFriction;
		} else
		{
			rotation += rotationFriction;
		}

		//gravitation
		if ( jogador->getPositionY() > 1 )
		{
			String::draw(100,160,"Caindo com gravidade...");
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
		
		skysphere->position( jogador );
		camera->setToFollow( jogador, ANGLE_Y, 40, 10, cameraSmooth, 1 );

		Game::refresh();
	}
	return ;

}