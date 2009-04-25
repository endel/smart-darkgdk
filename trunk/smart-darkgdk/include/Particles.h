#pragma once
#include "commonobject.h"
#include "ObjectType.h"

class Image;

class Particles :
	public CommonObject
{
private:
	bool visible;
public:
	Particles(void);
	Particles(Image *t, int frequency, float radius);
	Particles(ParticleType p, Image *t, int frequency, float x, float y, float z, float width, float height, float depth);
	Particles(ParticleType p, char* filename, int frequency, float x, float y, float z, float width, float height, float depth);
	~Particles(void);

	void show();
	void hide();
	void toggle();
	void position(float x,float y,float z);
	void positionEmissions(float x,float y,float z);
	void rotate(float x,float y,float z);
	void setColor(int r,int g,int b);
	void setEmissions(int frequency);
	void setGravity(float value);
	void setSpeed(int secondsPerFrame);
	void setChaos(float value);
	void setFloor(int flag);
	void setLife(int percentage);
	void setGhost(int ghostMode);
	void setGhost(bool disable);

	float positionX();
	float positionY();
	float positionZ();

};