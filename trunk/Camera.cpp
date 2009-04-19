#include "Camera.h"
#include "Game.h"
#include "Object.h"
#include "Image.h"

Camera::Camera(void)
{
	this->setId(Game::getCameraId());
	dbMakeCamera(this->id);
}
Camera::Camera(int n)
{
	this->setId(n);
}

Camera::~Camera(void)
{
	dbDeleteCamera(this->id);
}

void Camera::move(float step)
{
	dbMoveCamera(this->id,step);
}
void Camera::position(float x,float y, float z)
{
	dbPositionCamera(this->id,x,y,z);
}
void Camera::point(float x,float y, float z)
{
	dbPointCamera(this->id,x,y,z);
}
void Camera::rotate(float angleX,float angleY,float angleZ)
{
	dbRotateCamera(this->id,angleX,angleY,angleZ);
}
void Camera::rotateX(float angle)
{
	dbXRotateCamera(this->id,angle);
}
void Camera::rotateY(float angle)
{
	dbYRotateCamera(this->id,angle);
}
void Camera::rotateZ(float angle)
{
	dbZRotateCamera(this->id,angle);
}
void Camera::turnLeft(float angle)
{
	dbTurnCameraLeft(this->id,angle);
}
void Camera::turnRight(float angle)
{
	dbTurnCameraRight(this->id,angle);
}
void Camera::rollLeft(float angle)
{
	dbRollCameraLeft(this->id,angle);
}
void Camera::rollRight(float angle)
{
	dbRollCameraRight(this->id,angle);
}
void Camera::clearView(int r,int g,int b)
{
	dbClearCameraView(this->id,r,g,b);
}
void Camera::setFov(float fov)
{
	dbSetCameraFOV(this->id,fov);
}
void Camera::setRange(float front, float back)
{
	dbSetCameraRange(this->id,front,back);
}
void Camera::setView(float left,float top,float right,float bottom)
{
	dbSetCameraView(this->id,left,top,right,bottom);
}
void Camera::setRotationXYZ()
{
	dbSetCameraRotationXYZ();
}
void Camera::setRotationZYX()
{
	dbSetCameraRotationZYX();
}
void Camera::setToFollow(float x,float y,float z,float angle,float distance, float height,float smooth, int collision)
{
	dbSetCameraToFollow(this->id,x,y,z,angle,distance,height,smooth,collision);
}
void Camera::setToImage(Image *t,int width,int height)
{
	dbSetCameraToImage(this->id,t->id,width,height);
}
void Camera::setToImage(Image *t,int width,int height,int genAlpha)
{
	dbSetCameraToImage(this->id,t->id,width,height,genAlpha);
}
void Camera::setToObjectOrientation(Object *o)
{
	dbSetCameraToObjectOrientation(this->id,o->id);
}
void Camera::controlUsingArrows(float moveSpeed,float turnSpeed)
{
	dbControlCameraUsingArrowKeys(this->id,moveSpeed,turnSpeed);
}