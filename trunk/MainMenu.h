#pragma once

enum MainMenuItem;

class MainMenu
{
private:
	MainMenuItem selected;
public:
	MainMenu(void);
	~MainMenu(void);
	void start();
	bool active();
	void end();
	
	void setSelected(MainMenuItem s);
	
	MainMenuItem getItemSelected();
};
