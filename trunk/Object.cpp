#include "ObjectType.h"
#include "Object.h"
#include "Game.h"
#include "Image.h"
#include "Mesh.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Effect.h"

Object::Object(void)
{
}
Object::Object(int id)
{
	this->setId(id);
}
Object::Object(char* filename)
{
	this->setId(Game::getObjectId());
	dbLoadObject(filename,this->id);
}
Object::Object(Mesh *m,Image *t)
{
	this->setId(Game::getObjectId());
	dbMakeObject(this->id,m->id,t->id);
};
Object::Object(float width,float height,float depth)
{
	this->setId(Game::getObjectId());
	dbMakeObjectBox(this->id,width,height,depth);
}
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
Object::Object(Object* second, int limb)
{
	this->setId(Game::getObjectId());
	//dbMakeObjectFromLimb(
}
Object::Object(float width, float height)
{
	this->setId(Game::getObjectId());
	dbMakeObjectPlain(this->id,width,height);
}
/*Object::Object(PlaneType t,float width, float height)
{
	this->setId(Game::getObjectId());
	switch (t) {
		case PLAIN: dbMakeObjectPlain(this->id,width,height);break;
		case PLANE: dbMakeObjectPlane(this->id,width,height);break;
	}
}*/
Object::Object(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
	this->setId(Game::getObjectId());
	dbMakeObjectTriangle(this->id,x1,y1,z1, x2,y2,z2, x3,y3,z3);
}

Object::~Object(void)
{
	dbDeleteObject(this->id);
}

void Object::show()
{
	dbShowObject(this->id);
}
void Object::hide()
{
	dbHideObject(this->id);
}
void Object::toggle()
{
	if (isVisible()) hide();
	else show();
}


void Object::play()
{
	dbPlayObject(this->id);
}
void Object::play(int start)
{
	dbPlayObject(this->id,start);
}
void Object::play(int start,int end)
{
	dbPlayObject(this->id,start,end);
}

void Object::loop()
{
	dbLoopObject(this->id);
}
void Object::loop(int start)
{
	dbLoopObject(this->id,start);
}
void Object::loop(int start, int end)
{
	dbLoopObject(this->id,start,end);
}

void Object::stop()
{
	dbStopObject(this->id);
}
void Object::setFrame(int f)
{
	dbSetObjectFrame(this->id,f);
}
void Object::setFrame(float f)
{
	dbSetObjectFrame(this->id,f);
}
void Object::setFrame(float f,int recalculateBounds)
{
	dbSetObjectFrame(this->id,f,recalculateBounds);
}
void Object::setFrameSpeed(int s)
{
	dbSetObjectSpeed(this->id,s);
}
void Object::position(float x,float y, float z)
{
	dbPositionObject(this->id, x, y, z);
}
void Object::position(Object* o)
{
	dbPositionObject(this->id,o->positionX(),o->positionY(),o->positionZ());
}
void Object::setPositionX(float x)
{
	dbPositionObject(this->id,x,this->positionY(),this->positionZ());
}
void Object::setPositionY(float y)
{
	dbPositionObject(this->id,this->positionX(),y,this->positionZ());
}
void Object::setPositionZ(float z)
{
	dbPositionObject(this->id,this->positionX(),this->positionY(),z);
}
void Object::scale(float xSize, float ySize, float zSize)
{
	dbScaleObject(this->id, xSize, ySize, zSize);
}
void Object::rotate(float xAngle, float yAngle, float zAngle)
{
	dbRotateObject(this->id, xAngle, yAngle, zAngle);
}
void Object::move(float speed)
{
	dbMoveObject(this->id, speed);
}
void Object::point(float x, float y, float z)
{
	dbPointObject(this->id, x, y, z);
}
void Object::moveDown(float v)
{
	dbMoveObjectDown(this->id,v);
}
void Object::moveLeft(float v)
{
	dbMoveObjectLeft(this->id,v);
}
void Object::moveRight(float v)
{
	dbMoveObjectRight(this->id,v);
}
void Object::moveUp(float v)
{
	dbMoveObjectUp(this->id,v);
}
void Object::setRotateX(float angle)
{
	dbXRotateObject(this->id,angle);
}
void Object::setRotateY(float angle)
{
	dbYRotateObject(this->id,angle);
}
void Object::setRotateZ(float angle)
{
	dbZRotateObject(this->id,angle);
}

void Object::rotateX(float angle)
{
	dbXRotateObject(this->id,this->angleX() + angle);
}
void Object::rotateY(float angle)
{
	dbYRotateObject(this->id,this->angleY() + angle);
}
void Object::rotateZ(float angle)
{
	dbZRotateObject(this->id,this->angleZ() + angle);
}

void Object::turnLeft(float v)
{
	dbTurnObjectLeft(this->id,v);
}
void Object::turnRight(float v)
{
	dbTurnObjectRight(this->id,v);
}
void Object::pitchUp(float v)
{
	dbPitchObjectUp(this->id,v);
}
void Object::pitchDown(float v)
{
	dbPitchObjectDown(this->id,v);
}
void Object::rollLeft(float v)
{
	dbRollObjectLeft(this->id,v);
}
void Object::rollRight(float v)
{
	dbRollObjectRight(this->id,v);
}

void Object::setGhost(bool g)
{
	if (g) dbGhostObjectOn(this->id);
	else dbGhostObjectOff(this->id);
}
void Object::setLight(bool l)
{
	dbSetObjectLight(this->id,l);
}
void Object::setGhost(bool g,int mode)
{
	if (g) dbGhostObjectOn(this->id,mode);
	else dbGhostObjectOff(this->id);
}
void Object::setTexture(Image *t)
{
	dbTextureObject(this->id,t->id);
}
void Object::applyShader(VertexShader *s)
{
	vertexShaderOn = true;
	dbSetVertexShaderOn(this->id,s->id);
}
void Object::applyShader(PixelShader *s)
{
	pixelShaderOn = true;
	dbSetPixelShaderOn(this->id,s->id);
}
void Object::removeShader()
{
	if (vertexShaderOn) dbSetVertexShaderOff(this->id);
	if (pixelShaderOn) dbSetPixelShaderOff(this->id);
}
void Object::applyEffect(Effect *e)
{
	dbSetObjectEffect(this->id,e->id);
	dbPerformChecklistForEffectValues(e->id);
}
void Object::removeEffect()
{
}
void Object::fixPivot()
{
	dbFixObjectPivot(this->id);
}

//getters
bool Object::isPlaying()
{
	return dbObjectPlaying(this->id);
}
bool Object::isVisible()
{
	return dbObjectVisible(this->id);
}
bool Object::isLooping()
{
	return dbObjectLooping(this->id);
}
float Object::positionX()
{
	return dbObjectPositionX(this->id);
}
float Object::positionY()
{
	return dbObjectPositionY(this->id);
}
float Object::positionZ()
{
	return dbObjectPositionZ(this->id);
}
float Object::size()
{
	return dbObjectSize(this->id);
}
float Object::sizeX()
{
	return dbObjectSizeX(this->id);
}
float Object::sizeY()
{
	return dbObjectSizeY(this->id);
}
float Object::sizeZ()
{
	return dbObjectSizeZ(this->id);
}
float Object::angleX()
{
	return dbObjectAngleX(this->id);
}
float Object::angleY()
{
	return dbObjectAngleY(this->id);
}
float Object::angleZ()
{
	return dbObjectAngleZ(this->id);
}
float Object::frame()
{
	return dbObjectFrame(this->id);
}
float Object::speed()
{
	return dbObjectSpeed(this->id);
}
float Object::interpolation()
{
	return dbObjectInterpolation(this->id);
}
float Object::totalFrames()
{
	return dbTotalObjectFrames(this->id);
}
float Object::inScreen()
{
	return dbObjectInScreen(this->id);
}
float Object::screenX()
{
	return dbObjectScreenX(this->id);
}
float Object::screenY()
{
	return dbObjectScreenY(this->id);
}

bool Object::exists()
{
	if (!this->id) return false;
	else return dbObjectExist(this->id);
}

bool Object::hit(Object* o)
{
	return dbObjectHit(this->id,o->id);
}
Object* Object::hit()
{
	return new Object(dbObjectHit(this->id,0));
}
bool Object::collision(Object* o)
{
	return dbObjectCollision(this->id,o->id);
}
Object* Object::collision()
{
	return new Object(dbObjectCollision(this->id,0));
}
float Object::collisionRadius()
{
	return dbObjectCollisionRadius(this->id);
}
float Object::collisionCenterX()
{
	return dbObjectCollisionCenterX(this->id);
}
float Object::collisionCenterY()
{
	return dbObjectCollisionCenterY(this->id);
}
float Object::collisionCenterZ()
{
	return dbObjectCollisionCenterZ(this->id);
}
float Object::intersect(float x, float y, float z, float newX, float newY, float newZ)
{
	return dbIntersectObject(this->id, x, y, z, newX, newY, newZ);
}