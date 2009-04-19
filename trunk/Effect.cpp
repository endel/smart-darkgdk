#include "Effect.h"
#include "Game.h"
#include "Object.h"
#include "Matrix4.h"

Effect::Effect(char* filename, int useDefaultImages)
{
	this->setId(Game::getEffectId());
	dbLoadEffect(filename,this->id,useDefaultImages);
}

Effect::~Effect(void)
{
	dbDeleteEffect(this->id);
}
void Effect::apply(Object *o)
{
	o->applyEffect(this);
}

void Effect::setConstant(char* name, bool value)
{
	dbSetEffectConstantBoolean(this->id,name,value);
}
void Effect::setConstant(char* name, float value)
{
	dbSetEffectConstantFloat(this->id,name,value);
}
void Effect::setConstant(char* name, int value)
{
	dbSetEffectConstantInteger(this->id,name,value);
}
void Effect::setConstant(char* name, Matrix4* m)
{
	dbSetEffectConstantMatrix(this->id,name,m->id);
}
/*void Effect::setConstant(char* name, Vector* value)
{
}*/