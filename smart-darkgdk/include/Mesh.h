#pragma once
#include "CommonObject.h"

class Mesh
	: public CommonObject
{
public:
	Mesh(void);
	Mesh(char* filename);
	~Mesh(void);
	void load(char* filename);
	void save(char* filename);
};
