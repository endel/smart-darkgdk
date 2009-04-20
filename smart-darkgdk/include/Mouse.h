#pragma once

class Mouse
{
private:
	static bool visible;
public:
	Mouse(void);
	~Mouse(void);
	//setters
	static void hide();
	static void show();
	static void toggle();
	static void change(int id);
	static void setPosition(int x, int y);

	//getters
	static bool isVisible();
	static int moveX();
	static int moveY();
	static int moveZ();
	
	static int positionX();
	static int positionY();
	static int positionZ();

	static int click();
};

