#pragma once
#include "Sprite.h"
#include <vector>

class Lives
{
private:
	bool visible;
	int max;
	int number;
	std::vector<Sprite*> sprites;
	char* filename;

	int x,y,distance;
	bool horizontal;
public:
	Lives(void);
	Lives(char* spriteFilename, int numLives);
	~Lives(void);
	
	//setters
	void setup(char* spriteFilename, int numLives);
	void show();
	void hide();
	void toggle();
	void setPosition(int p_x, int p_y, int p_distance=4, bool p_horizontal=true);
	void add();
	void remove();

	//getters
	bool isVisible();
};
