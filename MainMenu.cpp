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