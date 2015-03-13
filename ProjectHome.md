## Overview ##
Smart DarkGDK is a toolkit based on [GameCreators's DarkGDK](http://gdk.thegamecreators.com/) library.

Clear and easy to learn, allows you to quickly develop 2D and 3D games.


## Demo game screenshot (included on sources) ##
![http://img200.imageshack.us/img200/8783/smartdarkgdk.jpg](http://img200.imageshack.us/img200/8783/smartdarkgdk.jpg)


## Simple code sample ##
```
#include "smart-darkgdk/Game.h"

void DarkGDK ( void )
{
	//Setup Smart DarkGDK
	Game::init("Hello Smart DarkGDK",800,600);
	
	//Create ground matrix
	Matrix* matrix = new Matrix(2000,2000,20,20);
	matrix->prepareImage("grass_T.BMP");//apply texture to the ground

	//Create the Skysphere
	Object* skysphere = new Object(SPHERE,-1500);
	skysphere->setLight(false);
	skysphere->setImage("sky.jpg");

	//Loads 3d model of the asteroid
	Object* asteroid = new Object("Asteroids/AST_01.X");
	asteroid->position(50,50,50);

	//Loads 3d model of the player and setup their attributes
	Object* player = new Object("Ship/Ship.X");

	//Create the camera
	Camera* camera = new Camera();
	
	//Game loop
	while ( Game::loop() )
	{
		//Draw debug string
		String::draw(5,5,String::convert(Key::scanCode()));
		
		//Move player forward
		if ( Key::check(KEY_W) )
			player->move(5.0f);

		//Move player backward
		if ( Key::check(KEY_S) )
			player->move(-5.0f);
		
		//Turn player left
		if ( Key::check(KEY_A) )
			player->rotateY(-1);

		//Turn player right
		if ( Key::check(KEY_D) )
			player->rotateY(1);
		
		//Rotate the player according to the mouse
		player->rotateY(Mouse::moveX()/10);
		player->rotateX(-(Mouse::moveY()/10));
		
		//Set camera in third person on player
		camera->setToFollow(player, ANGLE_Y, 200, 50, 20.0, 1);

		//Do Skysphere technique
		skysphere->position(player);
		
		//Position the mouse to the center of the game screen
		Mouse::setPosition(Game::width()/2,Game::height()/2);

		//Synchonize the game
		Game::refresh();
	}

	return;
}
```

## Get started ##
To get started with Smart DarkGDK library you will need:
  1. [Microsoft's Visual C++ 2008 Express](http://www.microsoft.com/express/vc/)
  1. [August 2007 DirectX 9.0c SDK](http://download.microsoft.com/download/3/3/f/33f1af6e-c61b-4f14-a0de-3e9096ed4b3a/dxsdk_aug2007.exe)
  1. [Dark GDK](http://go.microsoft.com/?linkid=7708310)


_**Current version:** Smart DarkGDK RC1_