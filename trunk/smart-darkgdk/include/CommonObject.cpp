#include "CommonObject.h"

CommonObject::CommonObject(void)
{
}
CommonObject::~CommonObject(void)
{
}
bool CommonObject::operator==(const CommonObject *c) const {
	return c->id == this->id;
}

void CommonObject::setId(int n)
{
	this->id = n;
}