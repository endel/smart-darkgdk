#pragma once

class Joystick
{
public:
	Joystick(void);
	~Joystick(void);

	static bool up();
	static bool down();
	static bool left();
	static bool right();
	static bool x();
	static bool y();
	static bool z();
	static bool fireA();
	static bool fireB();
	static bool fireC();
	static bool fireD();
	static bool fireX(int n);
	static bool fireXL(int n);
	static int sliderA();
	static int sliderB();
	static int sliderC();
	static int sliderD();
	static bool twistX();
	static bool twistY();
	static bool twistZ();
	static int hatAngle(int hatNumber);

};
