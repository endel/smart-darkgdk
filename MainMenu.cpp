#include "smart-darkgdk/Game.h"

#include <iostream>

#include "MainMenu.h"
#include "PlaneFightDefs.h"

MainMenu::MainMenu(void)
{
}

MainMenu::~MainMenu(void)
{
}

void MainMenu::start()
{
	looping = true;
	background = new Sprite("MainMenu.jpg");
	
	Mouse::hide();

	int menu_pos_x = 555;
	int menu_pos_y = 300;
	int menu_pos_y_offset = 0;
	
	iStart = new Sprite("start_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iStart2 = new Sprite("start_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iStart2->hide();
	menu_pos_y_offset += 50;

	iRecords = new Sprite("records_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iRecords2 = new Sprite("records_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iRecords2->hide();
	menu_pos_y_offset += 50;
	
	iCredits = new Sprite("credits_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iCredits2 = new Sprite("credits_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iCredits2->hide();
	menu_pos_y_offset += 50;

	iQuit = new Sprite("quit_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iQuit2 = new Sprite("quit_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iQuit2->hide();

	cursorSprite = new Sprite("cursor.png",0,0);
	cursor = new Sprite("cursor_real.png",0,0);
}

bool MainMenu::active()
{

	cursor->position( Mouse::positionX()+4, Mouse::positionY()+4 );
	cursorSprite->position( Mouse::positionX(), Mouse::positionY() );
	
	bool overStart = cursor->collision(iStart);
	bool overRecords = cursor->collision(iRecords);
	bool overCredits = cursor->collision(iCredits);
	bool overQuit = cursor->collision(iQuit);

	if (overStart)
	{
		if (Mouse::click()) {
			looping = false; 
			selected = START;
			end();
		}

		iStart->hide();
		iStart2->show();
		
		iRecords->show();
		iRecords2->hide();
		iCredits->show();
		iCredits2->hide();
		iQuit->show();
		iQuit2->hide();
	}

	if (overRecords)
	{
		if (Mouse::click()) {
			looping = false;
			selected = RECORDS;
			end();
		}

		iRecords->hide();
		iRecords2->show();

		iStart->show();
		iStart2->hide();
		iCredits->show();
		iCredits2->hide();
		iQuit->show();
		iQuit2->hide();
	}

	if (overCredits)
	{
		if (Mouse::click())  {
			looping = false;
			selected = CREDITS;
			end();
		}

		iCredits->hide();
		iCredits2->show();

		iStart->show();
		iStart2->hide();
		iRecords->show();
		iRecords2->hide();
		iQuit->show();
		iQuit2->hide();
	}

	if (overQuit)
	{
		if (Mouse::click()) {
			looping = false;
			selected = QUIT;
			end();
		}

		iQuit->hide();
		iQuit2->show();

		iStart->show();
		iStart2->hide();
		iRecords->show();
		iRecords2->hide();
		iCredits->show();
		iCredits2->hide();
	}

	if (!overStart && !overRecords && !overCredits && !overQuit) {
		iStart->show();
		iStart2->hide();

		iRecords->show();
		iRecords2->hide();

		iCredits->show();
		iCredits2->hide();

		iQuit->show();
		iQuit2->hide();
	}

	return looping;
}

void MainMenu::end()
{
	delete background;
	
	delete iStart;
	delete iStart2;

	delete iRecords;
	delete iRecords2;
	
	delete iCredits;
	delete iCredits2;

	delete iQuit;
	delete iQuit2;

	delete cursorSprite;
	delete cursor;
}


void MainMenu::setSelected(MainMenuItem s)
{
	selected = s;
}
MainMenuItem MainMenu::getItemSelected()
{
	return selected;
}