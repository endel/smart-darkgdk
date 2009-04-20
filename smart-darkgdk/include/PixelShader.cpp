#include "DarkGDK.h"
#include "PixelShader.h"
#include "../Game.h"
#include "Object.h"
#include "Image.h"

PixelShader::PixelShader(char* filename)
{
	this->setId(Game::getPixelShaderId());
	dbCreatePixelShaderFromFile(this->id,filename);
}

PixelShader::~PixelShader(void)
{
	dbDeletePixelShader(this->id);
}
void PixelShader::apply(Object *o)
{
	o->applyShader(this);
}
void PixelShader::setTexture(int slot,Image *t)
{
	dbSetPixelShaderTexture(this->id, slot, t->id);
}