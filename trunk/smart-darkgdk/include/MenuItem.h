#pragma once

class Sprite;

class MenuItem
{
private:
	Sprite *item;

	Sprite *hold;
	Sprite *active;
public:
	MenuItem(void);
	MenuItem(char* filename1, char* filename2);
	~MenuItem(void);
};
