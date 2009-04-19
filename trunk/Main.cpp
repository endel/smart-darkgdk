#include "Game.h"

void DarkGDK ( void )
{
	Game::init("Teste",800,600);
	
	Game::setDir("Media/");
	Mouse::hide();
	
	Matrix* matrix = new Matrix(2000,2000,20,20);
	matrix->prepareTexture(new Image("grass_T.BMP"));

	Object* skysphere = new Object(SPHERE,-1500);

	skysphere->setLight(false);
	skysphere->setTexture(new Image("sky.jpg"));

	Object* asteroid = new Object("Asteroids/AST_01.X");
	asteroid->position(50,50,50);

	Object* player = new Object("Ship/Ship.X");
	player->scale(40,40,40);
	player->rotate(-90,-90,0);
	player->fixPivot();
	player->position(Game::width()/2,0,Game::height()/2);

	Camera* camera = new Camera();
	camera->setRotationZYX();
	
	while ( Game::loop() )
	{
		String::draw(5,5,String::convert(Key::scanCode()));
		String::draw(5,30,String::convert(dbKeyState(KEY_W)));
		///Key::get
		
		if ( Key::check(KEY_W) )//up
			player->move(5.0f);
		if ( Key::check(KEY_S) )//down
			player->move(-5.0f);
		
		if ( Key::check(KEY_A) )//left
			player->rotateY(-1);

		if ( Key::check(KEY_D) )//right
			player->rotateY(1);
		
		player->rotateY(Mouse::moveX()/10);
		player->rotateX(-(Mouse::moveY()/10));
		player->rotateZ(Mouse::moveZ()/10);
		
		camera->setToFollow(player->positionX(), player->positionY(), player->positionZ(), player->angleY(), 200, 50, 20.0f, 1);
		skysphere->position(player);
		
		Mouse::setPosition(Game::width()/2,Game::height()/2);
		Game::refresh();
	}

	return;
}