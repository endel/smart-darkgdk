#pragma once
#include "CommonObject.h"
#include "ObjectType.h"
#include "Mesh.h"
#include "Image.h"
class VertexShader;
class PixelShader;
class Effect;

class Object : 
	public CommonObject
{
private:
	//control
	bool	pixelShaderOn,
			vertexShaderOn;
public:
	Object(void);
	Object(int id);
	Object(char* filename);
	Object(Mesh *m,Image *t);
	Object(float width,float height,float depth);
	Object(ObjectType t, float size);
	Object(Object* second, int limb);
	Object(float width, float height);
	Object(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	~Object(void);

	void show();
	void hide();
	void toggle();


	void play();
	void play(int start);
	void play(int start,int end);

	void loop();
	void loop(int start);
	void loop(int start, int end);

	void stop();
	void setFrame(int f);
	void setFrame(float f);
	void setFrame(float f,int recalculateBounds);
	void setFrameSpeed(int s);
	void position(float x,float y, float z);
	void position(Object* o);
	void setPositionX(float x);
	void setPositionY(float y);
	void setPositionZ(float z);
	void scale(float xSize, float ySize, float zSize);
	void rotate(float xAngle, float yAngle, float zAngle);
	void move(float speed);
	void point(float x, float y, float z);
	void moveDown(float v);
	void moveLeft(float v);
	void moveRight(float v);
	void moveUp(float v);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);
	void setRotateX(float angle);
	void setRotateY(float angle);
	void setRotateZ(float angle);
	void turnLeft(float v);
	void turnRight(float v);
	void pitchUp(float v);
	void pitchDown(float v);
	void rollLeft(float v);
	void rollRight(float v);
	void setGhost(bool g=true);
	void setGhost(bool g=true,int mode=0);
	void setLight(bool l);
	void setTexture(Image *t);

	void applyShader(VertexShader *s);
	void applyShader(PixelShader *s);
	void removeShader();
	void applyEffect(Effect *e);
	void removeEffect();

	void fixPivot();


	//getters
	bool isPlaying();
	bool isVisible();
	bool isLooping();
	float positionX();
	float positionY();
	float positionZ();
	float size();
	float sizeX();
	float sizeY();
	float sizeZ();
	float angleX();
	float angleY();
	float angleZ();
	float frame();
	float speed();
	float interpolation();
	float totalFrames();
	float inScreen();
	float screenX();
	float screenY();

	bool exists();

	bool hit(Object* o);
	Object* hit();
	bool collision(Object* o);
	Object* collision();

	float collisionRadius();
	float collisionCenterX();
	float collisionCenterY();
	float collisionCenterZ();
	float intersect(float x, float y, float z, float newX, float newY, float newZ);
};