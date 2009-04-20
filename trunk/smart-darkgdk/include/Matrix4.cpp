#include "Matrix4.h"
#include "../Game.h"

Matrix4::Matrix4(void)
{
	this->setId(Game::getMatrix4Id());
	dbMakeMatrix4(this->id);
}

Matrix4::~Matrix4(void)
{
	dbDeleteMatrix4(this->id);
}

void Matrix4::copyWorld()
{
	dbWorldMatrix4(this->id);
}
void Matrix4::copyView()
{
	dbViewMatrix4(this->id);
}
float Matrix4::inverse(Matrix4 *m)
{
	return dbInverseMatrix4(this->id,m->id);
}
void Matrix4::multiply(Matrix4 *m1, Matrix4 *m2)
{
	dbMultiplyMatrix4(this->id,m1->id,m2->id);
}
void Matrix4::multiply(float value)
{
	dbMultiplyMatrix4(this->id,value);
}