#pragma once
#include "commonobject.h"

class Image;
class Object;

class Terrain :
	public CommonObject
{
public:
	Terrain();
	~Terrain(void);

	void load(char *filename);
	void save(char *filename);
	void setup();
	void build();
	void update();

	void setScale(float x, float y, float z);
	void setSplit(int split);
	void setTiling(int tile);
	void setHeightmap(char* filename);
	void setTexture(Image *texture, int detail=1);
	Image *setTexture(char* imagePath, int detail=1);
	void setLight( float fXDir, float fYDir, float fZDir, int iRed, int iGreen, int iBlue, float fScale );

	float getGroundHeight(float x, float z);
	float getGroundHeight(Object *o);
	float getXSize();
	float getZSize();


};
