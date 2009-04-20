#pragma once
#include "Commonobject.h"

class Image 
	: public CommonObject
{
public:
	//Image(void);
	Image(void);
	Image(char* filename);
	Image(char* filename,int flag);
	Image(char* filename,int flag,int divideSize);
	~Image(void);
	bool exist();

	//statics
	static void setColorkey(int r,int g,int b);
//GET IMAGE : GET IMAGE Image Number, Left, Top, Right, Bottom
//PASTE IMAGE : PASTE IMAGE Image Number, X, Y

};
