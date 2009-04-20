#include "Key.h"
#include "DarkGDK.h"

Key::Key(void)
{
}

Key::~Key(void)
{
}

bool Key::up()
{
	return dbUpKey();
}
bool Key::down()
{
	return dbDownKey();
}
bool Key::left()
{
	return dbLeftKey();
}
bool Key::right()
{
	return dbRightKey();
}
bool Key::ctrl()
{
	return dbControlKey();
}
bool Key::shift()
{
	return dbShiftKey();
}
bool Key::enter()
{
	return dbReturnKey();
}
bool Key::escape()
{
	return dbEscapeKey();
}
bool Key::space()
{
	return dbSpaceKey();
}
int Key::scanCode()
{
	return dbScanCode();
}
bool Key::check(int scanCode)
{
	return dbKeyState(scanCode);
}
char* Key::entry()
{
	return dbEntry();
}
char* Key::getClipboard()
{
	return dbGetClipboard();
}
int Key::getRegistry()
{
	//return dbGetRegistry();
	return 0;
}