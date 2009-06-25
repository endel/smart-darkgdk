#include "smart-darkgdk/Game.h"

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
	background = new Sprite("MainMenu.jpg");
	
	int menu_pos_x = 555;
	int menu_pos_y = 300;
	int menu_pos_y_offset = 0;

	iStart = new Sprite("start_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iStart2 = new Sprite("start_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	menu_pos_y_offset += 50;

	iRecords = new Sprite("records_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iRecords2 = new Sprite("records_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	menu_pos_y_offset += 50;
	
	iCredits = new Sprite("credits_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iCredits2 = new Sprite("credits_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	menu_pos_y_offset += 50;

	iQuit = new Sprite("quit_0.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);
	iQuit2 = new Sprite("quit_1.png", menu_pos_x, menu_pos_y+menu_pos_y_offset);

	//cria sprites e background para o menu
}

bool MainMenu::active()
{
	

	//loop de ação para o menu (tudo acontecer...)
	return true;//no final, retorna se ainda está no menu ou não
}

void MainMenu::end()
{
	//deleta os objetos criados no start()
	
}


void MainMenu::setSelected(MainMenuItem s)
{
	selected = s;
}
MainMenuItem MainMenu::getItemSelected()
{
	return selected;
}