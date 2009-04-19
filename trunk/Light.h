#pragma once
#include "commonobject.h"

#include "Object.h"

class Light :
	public CommonObject
{
private:
	bool visible;
public:
	Light(void);
	~Light(void);

	void make();

	//setters
	void show();
	void hide();
	void toggle();

	void color(int r, int g, int b);
	void position(float x,float y,float z);
	void rotate(float x,float y,float z);
	void point(float x,float y,float z);

	void setDirectional(float x,float y,float z);
	void setPoint(float x,float y,float z);
	void setSpot(float inner,float outer);
	void setRange(int range);
	void setToObject(Object *o);
	void setToObjectPosition(Object* o);
	void setToObjectOrientation(Object* o);

/*
SET VECTOR3 TO LIGHT POSITION : SET VECTOR3 TO LIGHT POSITION Vector, Light Number
SET VECTOR3 TO LIGHT ROTATION : SET VECTOR3 TO LIGHT ROTATION Vector, Light Number
*/

	//getters
	bool isVisible();
	bool exist();
	bool type();
	float range();
	
	float positionX();
	float positionY();
	float positionZ();

	float directionX();
	float directionY();
	float directionZ();

	//statics

/*SET AMBIENT LIGHT : SET AMBIENT LIGHT Percentage
COLOR AMBIENT LIGHT : COLOR AMBIENT LIGHT Color Value*/

};
