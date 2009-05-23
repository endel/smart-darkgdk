#pragma once
#include "commonobject.h"

class CommonBSPCollider :
	public CommonObject
{
public:
	int collisionIndex;
	virtual char* getClassName() = 0;

	CommonBSPCollider(void);
	~CommonBSPCollider(void);
};
