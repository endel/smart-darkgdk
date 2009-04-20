#include "Joystick.h"
#include "DarkGDK.h"

Joystick::Joystick(void)
{
}

Joystick::~Joystick(void)
{
}

bool Joystick::up()
{
	return dbJoystickUp();
}
bool Joystick::down()
{
	return dbJoystickDown();
}
bool Joystick::left()
{
	return dbJoystickLeft();
}
bool Joystick::right()
{
	return dbJoystickRight();
}
bool Joystick::x()
{
	return dbJoystickX();
}
bool Joystick::y()
{
	return dbJoystickY();
}
bool Joystick::z()
{
	return dbJoystickZ();
}
bool Joystick::fireA()
{
	return dbJoystickFireA();
}
bool Joystick::fireB()
{
	return dbJoystickFireB();
}
bool Joystick::fireC()
{
	return dbJoystickFireC();
}
bool Joystick::fireD()
{
	return dbJoystickFireD();
}
bool Joystick::fireX(int n)
{
	return dbJoystickFireX(n);
}
bool Joystick::fireXL(int n)
{
	return dbJoystickFireXL(n);
}
int Joystick::sliderA()
{
	return dbJoystickSliderA();
}
int Joystick::sliderB()
{
	return dbJoystickSliderB();
}
int Joystick::sliderC()
{
	return dbJoystickSliderC();
}
int Joystick::sliderD()
{
	return dbJoystickSliderD();
}
bool Joystick::twistX()
{
	return dbJoystickTwistX();
}
bool Joystick::twistY()
{
	return dbJoystickTwistY();
}
bool Joystick::twistZ()
{
	return dbJoystickTwistZ();
}
int Joystick::hatAngle(int hatNumber)
{
	return dbJoystickHatAngle(hatNumber);
}