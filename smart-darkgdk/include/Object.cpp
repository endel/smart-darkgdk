#include "ObjectType.h"
#include "Object.h"
#include "../Game.h"
#include "DarkGDK.h"
#include "Image.h"
#include "Mesh.h"
#include "Limb.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Effect.h"
#include "BSP.h"
#include "Event.h"

//------------------------------------------------
//			  OPERATOR OVERLOADING
//------------------------------------------------

bool Object::operator==(Object* o)
{
	return (this->id == o->id);
}

//------------------------------------------------
//			  CONSTRUCTORS / DESTRUCTORS
//------------------------------------------------

Object::Object(int id)
{
	this->setId(id);
	_init();
}
//--

Object::Object(char* filename)
{
	this->setId(Game::getObjectId());
	dbLoadObject(filename,this->id);
	_init();
}
//--

Object::Object(Mesh *m,Image *t)
{
	this->setId(Game::getObjectId());
	dbMakeObject(this->id,m->id,t->id);
	_init();
}
//--

Object::Object(float width,float height,float depth)
{
	this->setId(Game::getObjectId());
	dbMakeObjectBox(this->id,width,height,depth);
	_init();
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
	_init();
}

void Object::execute(Event *e)
{
	position(999,999,999);
}

//--

Object::Object(Object* second, Limb *l)
{
	this->setId(Game::getObjectId());
	dbMakeObjectFromLimb( this->id, second->id, l->id);
	_init();
}
//--

Object::Object(float width, float height)
{
	this->setId(Game::getObjectId());
	dbMakeObjectPlain(this->id,width,height);
	_init();
}
//--

Object::Object(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
	this->setId(Game::getObjectId());
	dbMakeObjectTriangle(this->id,x1,y1,z1, x2,y2,z2, x3,y3,z3);
	_init();
}
//--

Object::~Object(void)
{
	dbDeleteObject(this->id);
}
//--

char* Object::getClassName()
{
	return "Object";
}
//--

Object* Object::clone()
{
	Object* cloned = new Object(Game::getObjectId());
	dbCloneObject(cloned->id,this->id);
	return cloned;

}

void Object::_init()
{
	if (BSP::getAllCollisionsEnabled()) {
		if (this->exists()) BSP::setCollisionOn(this);
	}

	locked = false;
	animationState = STOPPED;
	this->currentAnimation = new AnimationClip("none", 0, getTotalFrames(), 1, LOOP);
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







//------------------------------------------------
//					ANIMATION
//------------------------------------------------

void 
Object::addAnimation(char* p_name, int p_frameInicial, int p_frameFinal, int p_velocidade, WrapMode p_wrapMode)
{	
	this->animations[p_name] = new AnimationClip(p_name, p_frameInicial, p_frameFinal, p_velocidade, p_wrapMode);
}

//--

void
Object::playAnimation(char* p_animation)
{
	if(p_animation != this->currentAnimation->name)
	{
		AnimationClip* newAnimation = new AnimationClip(animations[p_animation]);

		this->currentAnimation = newAnimation;
		this->animFrame = newAnimation->frameInicial;
		this->animVelocity = newAnimation->velocidade;

		this->animationState = PLAYING;
	}
}
//--

void 
Object::crossFadeAnimation(char* p_animation, float p_switchVelocity)
{
	if(p_animation != this->currentAnimation->name)
	{
		AnimationClip* newAnimation = new AnimationClip(animations[p_animation]);

		this->currentAnimation = newAnimation;
		this->animFrame = newAnimation->frameInicial;
		this->animInterpPercent = 0.0f;
		this->animSwitchVelocity = p_switchVelocity;

		this->animationState = CHANGING;
	}
}
//--

void 
Object::stopAnimation()
{
	this->animationState = STOPPED;
	this->currentAnimation = new AnimationClip("none", 0, 0, 0, LOOP);
}
//--

void 
Object::setFrame(int p_frame)
{
	dbSetObjectFrame(this->id, p_frame);
}
//--

void 
Object::updateAnimation()
{
	switch(this->animationState)
	{
		//-->STOPPED
		case STOPPED:
		{
			dbSetObjectFrame(this->id, (int)this->animFrame);
			break;
		}

		//-->CHANGING
		case CHANGING:
		{
			this->animInterpPercent += this->animSwitchVelocity;
			
			if(this->animInterpPercent >= 100.0f)
			{
				this->animInterpPercent = 100.0f;
				dbSetObjectInterpolation(this->id, (int)this->animInterpPercent);
				this->animationState = PLAYING;
			}
			else
			{
				dbSetObjectInterpolation(this->id, (int)this->animInterpPercent);
			}

			dbSetObjectFrame(this->id, (int)this->animFrame);
			break;
		}

		//-->PLAYING
		case PLAYING:
		{
			this->animFrame += this->animVelocity * 0.1f;

			if(this->currentAnimation->wrapMode == LOOP)
			{
				if(this->animVelocity >= 0)
				{
					if(this->animFrame > this->currentAnimation->frameFinal)
					{
						this->animFrame = this->currentAnimation->frameInicial;
					}
				}
				else
				{
					if(this->animFrame < this->currentAnimation->frameInicial)
					{
						this->animFrame = this->currentAnimation->frameFinal;
					}
				}
			}
			else if(currentAnimation->wrapMode == ONCE)
			{
				if(this->animVelocity >= 0)
				{
					if(this->animFrame > this->currentAnimation->frameFinal)
					{
						this->animFrame = this->currentAnimation->frameFinal;
						this->animationState = STOPPED;
					}
				}
				else
				{
					if(this->animFrame < this->currentAnimation->frameInicial)
					{
						this->animFrame = this->currentAnimation->frameInicial;
						this->animationState = STOPPED;
					}
				}
			}

			dbSetObjectFrame(this->id, (int)this->animFrame);
			break;
		}
	}
}






//------------------------------------------------
//					TRANSFORM
//------------------------------------------------
void Object::setPosition(float x,float y, float z)
{
	dbPositionObject(this->id, x, y, z);
}
void Object::setPositionX(float val)
{
	this->setPosition(val,this->getPositionY(),this->getPositionZ());
}
//--
void Object::setPositionY(float val)
{
	this->setPosition(this->getPositionX(),val,this->getPositionZ());
}
//--
void Object::setPositionZ(float val)
{
	this->setPosition(this->getPositionX(),this->getPositionY(),val);
}
//--

void Object::setPosition(Object* o)
{
	dbPositionObject(this->id,o->getPositionX(),o->getPositionY(),o->getPositionZ());
}
//--

void Object::position(float x,float y, float z)
{
	setPosition(getPositionX() + x, getPositionY() + y, getPositionZ() + z);
}

void Object::positionX(float val)
{
	setPositionX(getPositionX() + val);
}
//--

void Object::positionY(float val)
{
	setPositionY(getPositionY() + val);
}
//--

void Object::positionZ(float val)
{
	setPositionZ(getPositionZ() + val);
}
//--


void Object::scale(float xSize, float ySize, float zSize)
{
	dbScaleObject(this->id, xSize, ySize, zSize);
}
//--

void Object::scale(float xyz)
{
	scale(xyz,xyz,xyz);
}

//--

void Object::rotation(float xAngle, float yAngle, float zAngle)
{
	dbRotateObject(this->id,xAngle,yAngle,zAngle);
}
void Object::rotationX(float angle)
{
	dbXRotateObject(this->id, angle);
}
void Object::rotationY(float angle)
{
	dbYRotateObject(this->id, angle);
}
void Object::rotationZ(float angle)
{
	dbZRotateObject(this->id, angle);
}
//--

void Object::rotate(float xAngle, float yAngle, float zAngle)
{
	dbRotateObject(this->id, this->getAngleX() + xAngle, this->getAngleY() + yAngle, this->getAngleZ() + zAngle);
}
void Object::rotateX(float angle)
{
	dbXRotateObject(this->id, this->getAngleX() + angle);
}
void Object::rotateY(float angle)
{
	dbYRotateObject(this->id, this->getAngleY() + angle);
}
void Object::rotateZ(float angle)
{
	dbZRotateObject(this->id, this->getAngleZ() + angle);
}
//--

void Object::localMove(float x, float y, float z)
{
	dbMoveObjectRight(this->id, x);
	dbMoveObjectUp(this->id, y);
	dbMoveObject(this->id, z);
}
//--

void Object::moveY(float v)
{
	dbMoveObjectUp(this->id, v);
}
//--

void Object::moveX(float v)
{
	dbMoveObjectRight(this->id, v);
}
//--

void Object::move(float v)
{
	dbMoveObject(this->id,v);
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

void Object::setEmissive(int r,int g,int b)
{
	dbSetObjectEmissive(this->id, RGB(r,g,b));
}
//--

void Object::setTexture(Image *t,int mode,int mipGeneration)
{
	dbTextureObject(this->id,t->id);
	
	if (mode != -1 || mipGeneration != -1)
		dbSetObjectTexture(this->id,mode,mipGeneration);
}
Image *Object::setTexture(char* imagePath,int mode,int mipGeneration)
{
	Image* t = new Image(imagePath);
	this->setTexture(t);
	if (mode != -1 || mipGeneration != -1)
		dbSetObjectTexture(this->id,mode,mipGeneration);
	return t;
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
//--

void Object::offsetTexture(float p_x, float p_y)
{
	dbScrollObjectTexture(this->id, p_x, p_y);
}
//--
void Object::showBoundingBox()
{
	dbShowObjectBounds(this->id);
}


void Object::showBounds(bool boxOnly)
{
	dbShowObjectBounds(this->id,boxOnly);
}

void Object::setColor(int r,int g,int b)
{
	dbColorObject(this->id,RGB(r,g,b));
}

void Object::lock()
{
	locked = true;
	dbLockObjectOn(this->id);
}

void Object::unlock()
{
	locked = false;
	dbLockObjectOff(this->id);
}

void Object::toggleLock()
{
	if (locked) unlock();
	else lock();
}

void Object::setSmoothing(float angle)
{
	dbSetObjectSmoothing(this->id,angle);
}

void Object::setSmoothing(int percentage)
{
	dbSetObjectSmoothing(this->id,percentage);
}

void Object::scaleTexture(float u, float v)
{
	dbScaleObjectTexture(this->id,u,v);
}

void Object::scrollTexture(float x, float y)
{
	dbScrollObjectTexture(this->id,x,y);
}

//------------------------------------------------
//					COLLISION
//------------------------------------------------

Limb* Object::addLimb(Object* o)
{
	return new Limb(o, this);
}

void Object::performCheckListForLimbs()
{
	dbPerformCheckListForObjectLimbs( this->id );
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
bool Object::exists()
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

void Object::makeBoxCollider(float p_x1, float p_y1, float p_z1, float p_x2, float p_y2, float p_z2)
{
	dbMakeObjectCollisionBox(this->id, p_x1, p_y1, p_z1, p_x2, p_y2, p_z2, 1);
}
//--

void Object::makeBoxCollider()
{
	dbSetObjectCollisionToBoxes(this->id);
}
//--

void Object::setAutomaticCollision(float radius, int response)
{
	dbAutomaticObjectCollision(this->id,radius,response);
}
//--

void Object::setCollisionType(eCollisionType c)
{
	switch (c)
	{
		case COLLISION_POLYGON: dbSetObjectCollisionToPolygons(this->id); break;
		case COLLISION_SPHERE: dbSetObjectCollisionToSpheres(this->id); break;
		default: COLLISION_BOX: dbSetObjectCollisionToBoxes(this->id); break;
	}
}
//--

void Object::collisionEnabled(bool flag)
{
	if(flag)	dbSetObjectCollisionOn(this->id);
	else		dbSetObjectCollisionOff(this->id);
}
//--

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