#pragma once
#include "commonobject.h"
#include "Image.h"

class Object;

class PixelShader :
	public CommonObject
{
public:
	PixelShader(char* filename);
	~PixelShader(void);
	void apply(Object *o);
	void setImage(int slot,Image *t);

/*CREATE PIXEL SHADER FROM FILE : CREATE PIXEL SHADER FROM FILE PixelShader Number, Shader Filename
DELETE PIXEL SHADER : DELETE PIXEL SHADER PixelShader Number
SET PIXEL SHADER ON : SET PIXEL SHADER ON Object Number, PixelShader Number
SET PIXEL SHADER OFF : SET PIXEL SHADER OFF Object Number
SET PIXEL SHADER Image : SET PIXEL SHADER Image PixelShader Number, Slot Number, Image Number*/

};
