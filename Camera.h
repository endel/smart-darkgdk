#pragma once
#include "commonobject.h"

class Image;
class Object;

class Camera :
	public CommonObject
{
public:
	Camera(void);
	Camera(int n);
	~Camera(void);

	void move(float step);
	void position(float x,float y, float z);
	void point(float x,float y, float z);
	void rotate(float angleX,float angleY,float angleZ);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);
	void turnLeft(float angle);
	void turnRight(float angle);
	void rollLeft(float angle);
	void rollRight(float angle);
	void clearView(int r,int g,int b);
	void setFov(float fov);
	void setRange(float front, float back);
	void setView(float left,float top,float right,float bottom);
	void setRotationXYZ();
	void setRotationZYX();
	void setToFollow(float x,float y,float z,float angle,float distance, float height,float smooth, int collision);
	void setToImage(Image *t,int width,int height);
	void setToImage(Image *t,int width,int height,int genAlpha);
	void setToObjectOrientation(Object *o);
	void controlUsingArrows(float moveSpeed,float turnSpeed);

};
