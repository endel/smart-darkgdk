#pragma once
#include "CommonObject.h"
#include "Image.h"

class Object;

class Matrix 
	: public CommonObject
{
public:
	Matrix(void);
	Matrix(float width,float depth,int xsegmented,int zsegmented);
	~Matrix(void);
	void make(float w,float d,int xsegmented,int zsegmented);

	void prepareImage(Image *t,int across=1,int down=1);
	Image* prepareImage(char* imagePath,int across=1,int down=1);
	void position(float x,float y,float z);
	void fill(float height,int tileNumber);
	void randomize(int maxHeight);
	
	void setGhost(bool g=true);
	void setGhost(bool g=true,int mode=0);
	void setWireframe(bool w);
	
	void setImage(int ImageMode=0,int mipMode=0);
	void configure(int wire,int transparency,int cull,int filter,int light,int fog,int ambient);

	void shiftDown();
	void shiftLeft();
	void shiftRight();
	void shiftUp();

	void setHeight(int tileX,int tileZ,float height);
	void setNormal(int tileX,int tileZ,float nx,int ny, int nz);
	void setTile(int tileX,int tileZ,int tileNumber);
	void update();

	float positionX();
	float positionY();
	float positionZ();
	int tileCount();
	bool tilesExist();
	int wireframeState();
	float groundHeight(float x, float z);
	float groundHeight(Object *o);
	float matrixHeight(int tileX,int tileZ);
	
	float getWidth();
	float getDepth();

private:
	float width, depth;


//SET VECTOR3 TO MATRIX POSITION : SET VECTOR3 TO MATRIX POSITION Vector, Matrix Numbers
};
