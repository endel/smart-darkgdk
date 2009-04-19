#include "ObjectType.h"
#include "Object.h"
#include "Game.h"
#include "Image.h"
#include "Mesh.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Effect.h"


//------------------------------------------------
//			  CONSTRUCTORS / DESTRUCTORS
//------------------------------------------------

Object::Object(int id)
{
	this->setId(id);
}
//--

Object::Object(char* filename)
{
	this->setId(Game::getObjectId());
	dbLoadObject(filename,this->id);
}
//--

Object::Object(Mesh *m,Image *t)
{
	this->setId(Game::getObjectId());
	dbMakeObject(this->id,m->id,t->id);
}
//--

Object::Object(float width,float height,float depth)
{
	this->setId(Game::getObjectId());
	dbMakeObjectBox(this->id,width,height,depth);
}
//--

Object::Object(ObjectType t, float size)
{
	this->setId(Game::getObjectId());
	switch (t)
	{
		case CONE: dbMakeObjectCone(this->id,size);break;
		case CUBE: dbMakeObjectCube(this->id,size);break;
		case CYLINDER: dbMakeObjectCylinder(this->id,size);break;
		case SPHERE: dbMakeObjectSphere(this->id,size);break;
	}
}
//--

Object::Object(Object* second, int limb)
{
	this->setId(Game::getObjectId());
	//dbMakeObjectFromLimb(
}
//--

Object::Object(float width, float height)
{
	this->setId(Game::getObjectId());
	dbMakeObjectPlain(this->id,width,height);
}
//--

Object::Object(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
	this->setId(Game::getObjectId());
	dbMakeObjectTriangle(this->id,x1,y1,z1, x2,y2,z2, x3,y3,z3);
}
//--

Object::~Object(void)
{
	dbDeleteObject(this->id);
}



//------------------------------------------------
//					VISIBILITY
//------------------------------------------------
void Object::show()
{
	dbShowObject(this->id);
}
//--

void Object::hide()
{
	dbHideObject(this->id);
}
//--

void Object::toggle()
{
	if (isVisible()) hide();
	else show();
}
//--




//------------------------------------------------
//					ANIMATION
//------------------------------------------------
void
Object::playAnimation(char* p_animation)
{
	dbSetObjectSpeed(this->id, this->animations[p_animation]->velocidade);
	dbLoopObject(this->id, this->animations[p_animation]->frameInicial, animations[p_animation]->frameFinal);
}
//--

void 
Object::addAnimation(char* p_name, int p_frameInicial, int p_frameFinal, int p_velocidade)
{	
	this->animations[p_name] = new AnimationClip(p_name, p_frameInicial, p_frameFinal, p_velocidade);
}
//--

void 
Object::stopAnimation()
{
	dbStopObject(this->id);
}
//--

void 
Object::setFrame(int p_frame)
{
	dbSetObjectFrame(this->id, p_frame);
}
//--




//------------------------------------------------
//					TRANSFORM
//------------------------------------------------
void Object::position(float x,float y, float z)
{
	dbPositionObject(this->id, x, y, z);
}
//--

void Object::position(Object* o)
{
	dbPositionObject(this->id,o->getPositionX(),o->getPositionY(),o->getPositionZ());
}
//--

void Object::scale(float xSize, float ySize, float zSize)
{
	dbScaleObject(this->id, xSize, ySize, zSize);
}
//--

void Object::rotation(float xAngle, float yAngle, float zAngle)
{
	dbXRotateObject(this->id, xAngle);
	dbYRotateObject(this->id, yAngle);
	dbZRotateObject(this->id, zAngle);
}
//--

void Object::rotate(float xAngle, float yAngle, float zAngle)
{
	dbXRotateObject(this->id, this->getAngleX() + xAngle);
	dbYRotateObject(this->id, this->getAngleY() + yAngle);
	dbZRotateObject(this->id, this->getAngleZ() + zAngle);
}
//--

void Object::localMove(int x, int y, int z)
{
	dbMoveObjectRight(this->id, x);
	dbMoveObjectUp(this->id, y);
	dbMoveObject(this->id, z);
}
//--

void Object::lookAt(float x, float y, float z)
{
	dbPointObject(this->id, x, y, z);
}
//--





//------------------------------------------------
//					RENDERER
//------------------------------------------------


void Object::setGhost(bool g,int mode)
{
	if (g) dbGhostObjectOn(this->id,mode);
	else dbGhostObjectOff(this->id);
}
//--

void Object::setLight(bool l)
{
	dbSetObjectLight(this->id,l);
}
//--

void Object::setImage(Image *t)
{
	dbTextureObject(this->id,t->id);
}
//--

void Object::applyShader(VertexShader *s)
{
	vertexShaderOn = true;
	dbSetVertexShaderOn(this->id,s->id);
}
//--

void Object::applyShader(PixelShader *s)
{
	pixelShaderOn = true;
	dbSetPixelShaderOn(this->id,s->id);
}
//--

void Object::removeShader()
{
	if (vertexShaderOn) dbSetVertexShaderOff(this->id);
	if (pixelShaderOn) dbSetPixelShaderOff(this->id);
}
//--

void Object::applyEffect(Effect *e)
{
	dbSetObjectEffect(this->id,e->id);
	dbPerformChecklistForEffectValues(e->id);
}
//--

void Object::removeEffect()
{
}
//--

void Object::fixPivot()
{
	dbFixObjectPivot(this->id);
}








//------------------------------------------------
//					GETTERS
//------------------------------------------------
bool Object::isPlaying()
{
	return dbObjectPlaying(this->id);
}
//--

bool Object::isVisible()
{
	return dbObjectVisible(this->id);
}
//--

bool Object::isLooping()
{
	return dbObjectLooping(this->id);
}
//--
bool Object::isExists()
{
	if (!this->id) return false;
	else return dbObjectExist(this->id);
}
//--

float Object::getPositionX()
{
	return dbObjectPositionX(this->id);
}
//--

float Object::getPositionY()
{
	return dbObjectPositionY(this->id);
}
//--

float Object::getPositionZ()
{
	return dbObjectPositionZ(this->id);
}
//--

float Object::getSize()
{
	return dbObjectSize(this->id);
}
//--

float Object::getSizeX()
{
	return dbObjectSizeX(this->id);
}
//--

float Object::getSizeY()
{
	return dbObjectSizeY(this->id);
}
//--

float Object::getSizeZ()
{
	return dbObjectSizeZ(this->id);
}
//--

float Object::getAngleX()
{
	return dbObjectAngleX(this->id);
}
//--

float Object::getAngleY()
{
	return dbObjectAngleY(this->id);
}
//--

float Object::getAngleZ()
{
	return dbObjectAngleZ(this->id);
}
//--

float Object::getFrame()
{
	return dbObjectFrame(this->id);
}
//--

float Object::getSpeed()
{
	return dbObjectSpeed(this->id);
}
//--

float Object::getInterpolation()
{
	return dbObjectInterpolation(this->id);
}
//--

float Object::getTotalFrames()
{
	return dbTotalObjectFrames(this->id);
}
//--

float Object::getInScreen()
{
	return dbObjectInScreen(this->id);
}
//--

float Object::getScreenX()
{
	return dbObjectScreenX(this->id);
}
//--

float Object::getScreenY()
{
	return dbObjectScreenY(this->id);
}
//--







//------------------------------------------------
//					COLLISION
//------------------------------------------------
bool Object::hit(Object* o)
{
	return dbObjectHit(this->id,o->id);
}
//--

Object* Object::hit()
{
	return new Object(dbObjectHit(this->id,0));
}
//--

bool Object::collision(Object* o)
{
	return dbObjectCollision(this->id,o->id);
}
//--

Object* Object::collision()
{
	return new Object(dbObjectCollision(this->id,0));
}
//--


float Object::getCollisionRadius()
{
	return dbObjectCollisionRadius(this->id);
}
//--

float Object::getCollisionCenterX()
{
	return dbObjectCollisionCenterX(this->id);
}
//--

float Object::getCollisionCenterY()
{
	return dbObjectCollisionCenterY(this->id);
}
//--

float Object::getCollisionCenterZ()
{
	return dbObjectCollisionCenterZ(this->id);
}
//--

float Object::intersect(float x, float y, float z, float newX, float newY, float newZ)
{
	return dbIntersectObject(this->id, x, y, z, newX, newY, newZ);
}