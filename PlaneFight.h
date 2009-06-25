#pragma once

#include "MainMenu.h"

class PlaneFight
{
private:
	int width, height;
	MainMenu menu;

	bool gameRunning;


//ingame vars
	int PROFUNDIDADE_CENARIO;
	int LARGURA_CENARIO;
	
	int score;

	//Airplane control
	float	acceleration,
			friction,
			speed,
			maxSpeed,
			bonusSpeed,

			gravity,
			flyAcceleration,
			gravitySpeed,
			maxGravity;

	float	rotation,
			rotationAcceleration,
			rotationReturning,
			rotationFriction,
			maxRotation;

	float	cameraSmooth;

	vector<Object*> addPoints;
	vector<Object*> enemies;
	Object *baseEnemy;
	int new_enemy_interval,
		new_enemy_count;

	Matrix	*cenario;
	Music	*backgroundMusic;
	Object	*parede;
	Object	*skysphere;
	Object	*jogador,
			*jogadorSprite;
	Object	*temp;
	Camera	*camera;
	Lives	*lives;
	Object	*obj1;
	Object	*obj2;
public:
	PlaneFight(void);
	~PlaneFight(void);
	void start();
	bool loop();

	//métodos para o jogo
	void loadGame();
	void hideGameObjs();
	void startGame();
	void gameLoop();
	void createEnemy();
};
