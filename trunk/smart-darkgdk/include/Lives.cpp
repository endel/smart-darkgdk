#include "Lives.h"
#include "Sprite.h"
#include <vector>

Lives::Lives(void)
{
}

Lives::~Lives(void)
{
}

Lives::Lives(char* spriteFilename, int numLives)
{
	setup(spriteFilename,numLives);
}
void Lives::setup(char* spriteFilename, int numLives)
{
	max = number = numLives;
	filename = spriteFilename;

	for (int i=0;i<number;i++)
	{
		sprites.push_back(new Sprite(filename));
	}
	setPosition(0,0);
}
void Lives::show()
{
	visible = true;
	for (int i=0;i<sprites.size();i++)
	{
		sprites.at(i)->show();
	}
}
void Lives::hide()
{
	visible = false;
	for (int i=0;i<sprites.size();i++)
	{
		sprites.at(i)->hide();
	}
}
void Lives::toggle()
{
	if (!visible) show();
	else hide();
}

bool Lives::isVisible()
{
	return visible;
}

void Lives::setPosition(int p_x, int p_y, int p_distance, bool p_horizontal)
{
	x = p_x;
	y = p_y;
	distance = p_distance;
	horizontal = p_horizontal;

	for (int i=0;i<sprites.size();i++)
	{
		int width = sprites.at(i)->getWidth();
		int height = sprites.at(i)->getHeight();

		int px = (horizontal) ? (x+(i*(width+distance))) : x;
		int py = (horizontal) ? y : (y+(i*(height+distance)));
		sprites.at(i)->position(px,py);
	}
}

void Lives::add()
{
	sprites.push_back(new Sprite(filename));
	setPosition(x, y, distance=2, horizontal);
}

void Lives::remove()
{
	Sprite* lastSprite = sprites.back();
	sprites.pop_back();
	delete lastSprite;
}