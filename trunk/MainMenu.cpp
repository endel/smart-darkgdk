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

void MainMenu::load()
{
	background = new Sprite("PlaneFight/MainMenu.jpg");

	int menu_pos_x = 555;
	int menu_pos_y = 300;
	int menu_pos_y_offset = 0;
	
	iStart = new Sprite("PlaneFight/start_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iStart2 = new Sprite("PlaneFight/start_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iStart2->hide();
	menu_pos_y_offset += 50;

	iRecords = new Sprite("PlaneFight/records_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iRecords2 = new Sprite("PlaneFight/records_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iRecords2->hide();
	menu_pos_y_offset += 50;
	
	iCredits = new Sprite("PlaneFight/credits_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iCredits2 = new Sprite("PlaneFight/credits_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iCredits2->hide();
	menu_pos_y_offset += 50;

	iQuit = new Sprite("PlaneFight/quit_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iQuit2 = new Sprite("PlaneFight/quit_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iQuit2->hide();

	cursorSprite = new Sprite("PlaneFight/cursor.png",0,0);
	cursor = new Sprite("PlaneFight/cursor_real.png",0,0);

	background->hide();
	iStart->hide();
	iRecords->hide();
	iCredits->hide();
	iQuit->hide();
	cursorSprite->hide();
	cursor->hide();
}

void MainMenu::start()
{
	looping = true;
	Mouse::hide();

	background->show();
	iStart->show();
	iRecords->show();
	iCredits->show();
	iQuit->show();
	cursorSprite->show();
	cursor->show();
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