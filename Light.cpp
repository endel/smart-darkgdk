
#include "Light.h"
#include "Game.h"


Light::Light(void)
{
	make();
}

Light::~Light(void)
{
	dbDeleteLight(this->id);
}

void Light::make()
{
	this->setId(Game::getLightId());
	dbMakeLight(this->id);
}

//setters
void Light::show()
{
	dbShowLight(this->id);
}
void Light::hide()
{
	dbHideLight(this->id);
}
void Light::toggle()
{
	if (isVisible()) hide();
	else show();
}
void Light::color(int r, int g, int b)
{
	dbColorLight(this->id, r, g, b);
}
void Light::position(float x,float y,float z)
{
	dbPositionLight(this->id,x,y,z);
}
void Light::rotate(float x,float y,float z)
{
	dbRotateLight(this->id,x,y,z);
}
void Light::point(float x,float y,float z)
{
	dbPointLight(this->id,x,y,z);
}
void Light::setDirectional(float x,float y,float z)
{
	dbSetDirectionalLight(this->id,x,y,z);
}
void Light::setPoint(float x,float y,float z)
{
	dbSetPointLight(this->id,x,y,z);
}
void Light::setSpot(float inner,float outer)
{
	dbSetSpotLight(this->id,inner,outer);
}
void Light::setRange(int range)
{
	dbSetLightRange(this->id,range);
}
void Light::setToObject(Object *o)
{
	dbSetLightToObject(this->id,o->id);
}
void Light::setToObjectPosition(Object* o)
{
	dbSetLightToObject(this->id,o->id);
}
void Light::setToObjectOrientation(Object* o)
{
	dbSetLightToObjectOrientation(this->id,o->id);
}

//setters
bool Light::isVisible()
{
	return dbLightVisible(this->id);
}
bool Light::exist()
{
	return dbLightExist(this->id);
}
bool Light::type()
{
	return dbLightType(this->id);
}
float Light::range()
{
	return dbLightRange(this->id);
}
float Light::positionX()
{
	return dbLightPositionX(this->id);
}
float Light::positionY()
{
	return dbLightPositionY(this->id);
}
float Light::positionZ()
{
	return dbLightPositionZ(this->id);
}
float Light::directionX()
{
	return dbLightDirectionX(this->id);
}
float Light::directionY()
{
	return dbLightDirectionY(this->id);
}
float Light::directionZ()
{
	return dbLightDirectionZ(this->id);
}

//statics
