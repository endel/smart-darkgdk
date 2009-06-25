#pragma once
#include "smart-darkgdk/Game.h"

enum MainMenuItem;

class MainMenu
{
private:
	bool looping;

	MainMenuItem selected;
	Sprite *background;
	
	Sprite *cursor, *cursorSprite;

	Sprite *iStart, *iStart2;
	Sprite *iRecords, *iRecords2;
	Sprite *iCredits, *iCredits2;
	Sprite *iQuit, *iQuit2;
public:
	MainMenu(void);
	~MainMenu(void);
	void start();
	bool active();
	void end();
	
	void setSelected(MainMenuItem s);
	
	MainMenuItem getItemSelected();
};
