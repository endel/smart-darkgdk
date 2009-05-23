#include "BSP.h"
#include "DarkGDK.h"
#include "CommonBSPCollider.h"
#include "Object.h"
#include "Camera.h"

int BSP::COLLISION_ID = 0;

BSP::BSP(void)
{
}

BSP::~BSP(void)
{
}


//setters

void BSP::load ( char* PK3Filename, char* BSPFilename )
{
	dbLoadBSP( PK3Filename, BSPFilename );
}

void BSP::unload ( void )
{
	dbDeleteBSP();
}

void BSP::setCamera ( Camera *c )
{
	dbSetBSPCamera(c->id);
}

void BSP::setCollisionOn ( Camera *c, float Radius, int Response )
{
	c->collisionIndex = getCollisionID();
	dbSetBSPCameraCollision(c->collisionIndex,c->id,Radius, Response);
}

void BSP::setCollisionOn ( Object *o, float Radius, int Response )
{
	o->collisionIndex = getCollisionID();
	dbSetBSPObjectCollision(o->collisionIndex,o->id,Radius, Response);
}

void BSP::setCollisionThreshold ( CommonBSPCollider *c, float Sensitivity )
{
	dbSetBSPCollisionThreshold(c->collisionIndex, Sensitivity);
}

void BSP::setCollisionOff ( CommonBSPCollider *c )
{
	dbSetBSPCollisionOff(c->collisionIndex);
}

void BSP::setCollisionRadius ( CommonBSPCollider *element, Camera *c, float X, float Y, float Z )
{
	dbSetBSPCameraCollisionRadius(element->collisionIndex, c->id, X, Y, Z);
}

void BSP::setCollisionRadius ( CommonBSPCollider *element, Object *o, float X, float Y, float Z )
{
	dbSetBSPObjectCollisionRadius(element->collisionIndex, o->id, X, Y, Z);
}

void BSP::setCollisionHeightAdjustment ( CommonBSPCollider *c, float Height )
{
	dbSetBSPCollisionHeightAdjustment(c->collisionIndex, Height);
}

void BSP::setMultiTexturingOn ( void )
{
	dbSetBSPMultiTexturingOn();
}

void BSP::setMultiTexturingOff ( void )
{
	dbSetBSPMultiTexturingOff();
}

void BSP::processCollision ( CommonBSPCollider *c )
{
	dbProcessBSPCollision(c->collisionIndex);
}


//getters
bool BSP::getCollisionHit ( CommonBSPCollider *c )
{
	return (bool)dbBSPCollisionHit(c->collisionIndex);
}

float BSP::getCollisionX ( CommonBSPCollider *c )
{
	return dbBSPCollisionX(c->collisionIndex);
}

float BSP::getCollisionY ( CommonBSPCollider *c )
{
	return dbBSPCollisionY(c->collisionIndex);
}

float BSP::getCollisionZ ( CommonBSPCollider *c )
{
	return dbBSPCollisionZ(c->collisionIndex);
}

int BSP::getCollisionID()
{
	return ++COLLISION_ID;
}