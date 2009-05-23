#include "BSP.h"
#include "../Game.h"
#include "DarkGDK.h"
#include "CommonBSPCollider.h"
#include "Object.h"
#include "Camera.h"

int BSP::COLLISION_ID = 0;
bool BSP::ENABLE_ALL_OBJECT_COLLISIONS = false;

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

void BSP::setCollisionOn ( Camera *c, float Radius, int Response)
{
	c->collisionIndex = getCollisionID();
	dbSetBSPCameraCollision(c->collisionIndex,c->id,Radius, Response);
}

void BSP::setCollisionOn ( Object *o, float Radius, int Response)
{
	o->collisionIndex = getCollisionID();
	if (Radius == 0) Radius = o->getSize();
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

void BSP::enableAllObjectCollisions()
{
	ENABLE_ALL_OBJECT_COLLISIONS = true;
	for (int i = 1;i<=Game::OBJECT_ID;i++)
	{
		Object *o = new Object(i);
		if (o->exists()) setCollisionOn(o);
	}
}
void BSP::disableAllObjectCollisions()
{
	ENABLE_ALL_OBJECT_COLLISIONS = false;
	for (int i = 1;i<=Game::OBJECT_ID;i++)
	{
		Object *o = new Object(i);
		if (o->exists()) setCollisionOff(o);
	}
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

bool BSP::getAllCollisionsEnabled()
{
	return ENABLE_ALL_OBJECT_COLLISIONS;
}