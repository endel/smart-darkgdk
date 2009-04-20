#pragma once
#include "commonobject.h"

class Object;
class Matrix4;

class Effect :
	public CommonObject
{
public:
	Effect(char* filename, int useDefaultImages=1);
	~Effect(void);
	
	void apply(Object *o);
	void setConstant(char* name, bool value);
	void setConstant(char* name, float value);
	void setConstant(char* name, int value);
	void setConstant(char* name, Matrix4* m);
	//void setConstant(char* name, Vector* value);
	

//dbSetEffectConstantVector
};
