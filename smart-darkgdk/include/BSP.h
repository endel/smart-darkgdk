#pragma once

class Object;
class Camera;
class CommonBSPCollider;

class BSP
{
public:
	BSP(void);
	~BSP(void);
	
	//setters
	static void load ( char* PK3Filename, char* BSPFilename );
	static void unload ( void );
	static void setCamera ( Camera *c );
	static void setCollisionOn ( Camera *c, float Radius, int Response=0 );
	static void setCollisionOn ( Object *o, float Radius=0, int Response=0 );
	static void setCollisionThreshold ( CommonBSPCollider *c, float Sensitivity );
	static void setCollisionOff ( CommonBSPCollider *c );
	static void setCollisionRadius ( CommonBSPCollider *element, Camera *c, float X, float Y, float Z );
	static void setCollisionRadius ( CommonBSPCollider *element, Object *o, float X, float Y, float Z );
	static void setCollisionHeightAdjustment ( CommonBSPCollider *c, float Height );
	static void setMultiTexturingOn ( void );
	static void setMultiTexturingOff ( void );
	static void processCollision ( CommonBSPCollider *c );

	static void enableAllObjectCollisions();
	static void disableAllObjectCollisions();

	//getters
	static bool getCollisionHit ( CommonBSPCollider *c );
	static float getCollisionX ( CommonBSPCollider *c );
	static float getCollisionY ( CommonBSPCollider *c );
	static float getCollisionZ ( CommonBSPCollider *c );

	//Collision ID's
	static int COLLISION_ID;
	static bool ENABLE_ALL_OBJECT_COLLISIONS;

	static int getCollisionID();
	static bool getAllCollisionsEnabled();
};