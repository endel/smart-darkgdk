#include "Mouse.h"
#include "../Game.h"

bool Mouse::visible = true;

Mouse::Mouse(void)
{
}

Mouse::~Mouse(void)
{
}

//setters
void Mouse::hide()
{
	visible = false;
	dbHideMouse();
}
void Mouse::show()
{
	visible = true;
	dbShowMouse();
}
void Mouse::toggle()
{
	if (visible) hide();
	else show();
}
void Mouse::change(int id)
{
	dbChangeMouse(id);
}
void Mouse::setPosition(int x, int y)
{
	dbPositionMouse(x,y);
}

//getters
int Mouse::moveX()
{
	return dbMouseMoveX();
}
int Mouse::moveY()
{
	return dbMouseMoveY();
}
int Mouse::moveZ()
{
	return dbMouseMoveZ();
}
int Mouse::positionX()
{
	return dbMouseX();
}
int Mouse::positionY()
{
	return dbMouseY();
}
int Mouse::positionZ()
{
	return dbMouseZ();
}
int Mouse::press(MouseClick c)
{
	return Game::LAST_MOUSE_CLICK == c;
}
int Mouse::click(MouseClick c)
{
	return Game::MOUSE_CLICK == c;
}