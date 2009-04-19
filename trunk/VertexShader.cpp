#include "VertexShader.h"
#include "Game.h"
#include "Object.h"

VertexShader::VertexShader(char* filename)
{
	this->setId(Game::getVertexShaderId());
	dbCreateVertexShaderFromFile(this->id,filename);
}

VertexShader::~VertexShader(void)
{
	dbDeleteVertexShader(this->id);
}
void VertexShader::apply(Object *o)
{
	o->applyShader(this);
}