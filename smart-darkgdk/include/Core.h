#pragma once

//-->MouseClick = Diferentes botões do mouse
enum MouseClick
{
	NO_CLICK = 0,
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	MIDDLE_CLICK = 4
};

//-->MouseClickState = Estados de clique mouse
enum MouseClickState
{
	MOUSE_STANDBY,
	MOUSE_PRESS,
	MOUSE_PRESSING,
	MOUSE_RELEASE
};