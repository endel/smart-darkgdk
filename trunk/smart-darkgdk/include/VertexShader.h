#pragma once
#include "commonobject.h"
class Object;

class VertexShader :
	public CommonObject
{
public:
	VertexShader(char* filename);
	~VertexShader(void);

	void apply(Object* o);

/*CREATE VERTEX SHADER FROM FILE : CREATE VERTEX SHADER FROM FILE VertexShader Number, Shader Filename
DELETE VERTEX SHADER : DELETE VERTEX SHADER VertexShader Number

SET VERTEX SHADER ON : SET VERTEX SHADER ON Object Number, VertexShader Number
SET VERTEX SHADER OFF : SET VERTEX SHADER OFF Object Number*/

/*SET VERTEX SHADER VECTOR : SET VERTEX SHADER VECTOR VertexShader Number, Constant, Vector3, ConstantCount
SET VERTEX SHADER MATRIX : SET VERTEX SHADER MATRIX VertexShader Number, Constant, Matrix4, ConstantCount
SET VERTEX SHADER STREAM : SET VERTEX SHADER STREAM VertexShader Number, Position, Data, Datatype
SET VERTEX SHADER STREAMCOUNT : SET VERTEX SHADER STREAMCOUNT VertexShader Number, Count
CONVERT OBJECT FVF : CONVERT OBJECT FVF Object Number, FVF Format*/

};
