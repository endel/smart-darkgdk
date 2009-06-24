#include "Camera.h"
#include "../Game.h"
#include "Object.h"

#include "ObjectType.h"




//------------------------------------------------
//			  CONSTRUCTORS / DESTRUCTORS
//------------------------------------------------

Camera::Camera()
{
	this->setId(Game::getCameraId());
	dbMakeCamera(this->id);
	this->setFov(45.0f);
	this->setClips(1.0f, 3000.0f);
}
//--

Camera::Camera(int n)
{
	this->setId(n);
}
//--
Camera::Camera(int fov, int nearClip, int farClip)
{
	this->setId(Game::getCameraId());
	dbMakeCamera(this->id);
	this->setFov(fov);
	this->setClips(nearClip, farClip);
}
//--

Camera::~Camera(void)
{
	dbDeleteCamera(this->id);
}

char* Camera::getClassName()
{
	return "Camera";
}





//------------------------------------------------
//					FUNCTIONS
//------------------------------------------------

void Camera::setCurrentCamera(Camera* camera)
{
	dbSetCurrentCamera(camera->id);
}
//--

void Camera::setFov(float fov)
{
	dbSetCameraFOV(this->id,fov);
}
//--

void Camera::setClips(float nearClip, float farClip)
{
	dbSetCameraRange(this->id, nearClip, farClip);
}
//--

void Camera::clearView(int r,int g,int b)
{
	dbClearCameraView(this->id,r,g,b);
}
//--

void Camera::backDropColor(int r, int g, int b)
{
	dbColorBackdrop(this->id, dbRGB(r, g, b));
}





void Camera::globalMove(float x, float y, float z)
{
	this->position(getPositionX() + x, getPositionY() + y, getPositionZ() + z);
}
//--

void Camera::localMove(float x, float y, float z)
{
	dbMoveCameraRight(this->id, x);
	dbMoveCameraUp(this->id, y);
	dbMoveCamera(this->id, z);
}
//--

void Camera::position(float x,float y, float z)
{
	dbPositionCamera(this->id,x,y,z);
}
//--
void Camera::position(Object *o)
{
	dbPositionCamera(this->id,o->getPositionX(),o->getPositionY(),o->getPositionZ());
}

void Camera::lookAt(float x,float y, float z)
{
	this->point(x,y,z);
}
void Camera::point(float x,float y, float z)
{
	dbPointCamera(this->id,x,y,z);
}
//--

void Camera::setRotation(float angleX,float angleY,float angleZ)
{
	dbRotateCamera(this->id,angleX,angleY,angleZ);
}
//--

void Camera::setRotation(Object *o)
{
	dbRotateCamera(this->id,o->getAngleX(),o->getAngleY(),o->getAngleZ());
}

void Camera::rotate(float angleX,float angleY,float angleZ)
{
	dbRotateCamera(this->id,this->getAngleX()+angleX,this->getAngleY()+angleY,this->getAngleZ()+angleZ);
}
//--

void Camera::turn(float q)
{
	if(q > 0) dbTurnCameraLeft(this->id, q);
	if(q < 0) dbTurnCameraRight(this->id, q);
}
//--

void Camera::follow3DPerson(Object* objeto, float distance, float height, float alturaVisao)
{
	this->position(objeto->getPositionX(), objeto->getPositionY(), objeto->getPositionZ()),
	this->setToObjectOrientation(objeto);
	this->localMove(0, height, -distance);
	this->lookAt(objeto->getPositionX(), alturaVisao, objeto->getPositionZ());
}
//--

void Camera::controlUsingArrowKeys(float velocity,float turnSpeed)
{
	dbControlCameraUsingArrowKeys(this->id,velocity,turnSpeed);
}
//--

void Camera::setView(float left,float top,float right,float bottom)
{
	dbSetCameraView(this->id,left,top,right,bottom);
}
//--

void Camera::setToFollow(float x,float y,float z,float angle,float distance, float height,float smooth, int collision)
{
	dbSetCameraToFollow(this->id,x,y,z,angle,distance,height,smooth,collision);
}
void Camera::setToFollow(Object* o,ANGLE a,float distance, float height,float smooth, int collision)
{
	int angle;
	switch (a)
	{
		case ANGLE_X: angle = o->getAngleX();break;
		case ANGLE_Y: angle = o->getAngleY();break;
		case ANGLE_Z: angle = o->getAngleZ();break;
	}
	dbSetCameraToFollow(this->id,o->getPositionX(),o->getPositionY(),o->getPositionZ(),angle,distance,height,smooth,collision);
}
//--

void Camera::setToImage(Image *t,int width,int height)
{
	dbSetCameraToImage(this->id,t->id,width,height);
}
//--

void Camera::setToImage(Image *t,int width,int height,int genAlpha)
{
	dbSetCameraToImage(this->id,t->id,width,height,genAlpha);
}
//--

void Camera::setToObjectOrientation(Object *o)
{
	dbSetCameraToObjectOrientation(this->id,o->id);
}
//--







//------------------------------------------------
//					GETTERS
//------------------------------------------------

float Camera::getPositionX()
{
	return dbCameraPositionX(this->id);
}
//--

float Camera::getPositionY()
{
	return dbCameraPositionY(this->id);
}
//--

float Camera::getPositionZ()
{
	return dbCameraPositionZ(this->id);
}
//--

float Camera::getAngleX()
{
	return dbCameraAngleX(this->id);
}
//--

float Camera::getAngleY()
{
	return dbCameraAngleY(this->id);
}
//--

float Camera::getAngleZ()
{
	return dbCameraAngleZ(this->id);
}
//--

float Camera::getDirectionX()
{
	return dbCameraLookX(this->id);
}
//--

float Camera::getDirectionY()
{
	return dbCameraLookY(this->id);
}
//--

float Camera::getDirectionZ()
{
	return dbCameraLookZ(this->id);
}

