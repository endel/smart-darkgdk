#pragma once
#include "CommonObject.h"

class Object;

class Mesh
	: public CommonObject
{
public:
	Mesh(void);
	Mesh(Object *o);
	Mesh(char* filename);
	~Mesh(void);
	void load(char* filename);
	void save(char* filename);
};
