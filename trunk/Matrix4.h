#pragma once
#include "commonobject.h"

class Matrix4 :
	public CommonObject
{
public:
	Matrix4(void);
	~Matrix4(void);

	void copyWorld();
	void copyView();
	void multiply(Matrix4 *m1, Matrix4 *m2);
	void multiply(float value);
	float inverse(Matrix4 *m);
};
