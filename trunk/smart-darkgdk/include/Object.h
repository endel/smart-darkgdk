#pragma once
#include "CommonObject.h"
#include "ObjectType.h"
#include "Mesh.h"
#include "Image.h"
#include "AnimationClip.h"
#include <map>
using namespace std;


class VertexShader;
class PixelShader;
class Effect;

class Object : 
	public CommonObject
{
	public:
	//------------------->CONSTRUCTORS / DESTRUCTORS<-------------------
	Object(int id);
	Object(char* filename);
	Object(Mesh *m,Image *t);
	Object(float width,float height,float depth);
	Object(ObjectType t, float size);
	Object(Object* second, int limb);
	Object(float width, float height);
	Object(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	~Object();





	//---------------------------->VISIBILITY<--------------------------
	void show();
	void hide();
	void toggle();





	//---------------------------->ANIMACAO<----------------------------

	//-->Adiciona animação
	void addAnimation(char* p_name, int p_frameInicial, int p_frameFinal, int p_velocidade, WrapMode p_wrapMode);

	//-->Play animação
	void playAnimation(char* p_animation);

	//-->Troca animação com fade
	void crossFadeAnimation(char* p_animation, float p_switchVelocity);

	//-->Pause animação
	void stopAnimation();

	//-->Seta frame
	void setFrame(int p_frame);

	//-->Atualiza animações personagem
	void updateAnimation();



	//----------------------------->TRANSFORM<---------------------------

	//-->Seta posição objeto
	void position(float x,float y, float z);
	void position(Object* o);

	//-->Scala objeto
	void scale(float xSize, float ySize, float zSize);

	//-->Seta rotacao objeto para tantos graus
	void rotation(float xAngle, float yAngle, float zAngle);
	void rotationX(float angle);
	void rotationY(float angle);
	void rotationZ(float angle);

	//-->Rotaciona objeto tantos graus
	void rotate(float xAngle, float yAngle, float zAngle);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);
	
	//-->Move objeto
	void localMove(float x, float y, float z);

	//-->Aponta para objeto
	void lookAt(float x, float y, float z);





	//----------------------------->RENDER<---------------------------
	
	//-->Objeto fica transparente
	void setGhost(bool g=true,int mode=0);

	//-->Seta iluminação
	void setLight(bool l);

	//-->Seta textura
	void setImage(Image *t);
	Image *setImage(char* imagePath);

	//-->Aplica Shaders
	void applyShader(VertexShader *s);
	void applyShader(PixelShader *s);
	
	//-->Remove Shader
	void removeShader();

	//-->Aplica / Remove effect
	void applyEffect(Effect *e);
	void removeEffect();

	//-->Arruma Pivo
	void fixPivot();

	//-->Move textura
	void offsetTexture(float p_x, float p_y);





	//----------------------------->GETTERS<---------------------------

	bool  isPlaying();
	bool  isVisible();
	bool  isLooping();
	bool  isExists();
	float getPositionX();
	float getPositionY();
	float getPositionZ();
	float getSize();
	float getSizeX();
	float getSizeY();
	float getSizeZ();
	float getAngleX();
	float getAngleY();
	float getAngleZ();
	float getFrame();
	float getSpeed();
	float getInterpolation();
	float getTotalFrames();
	float getInScreen();
	float getScreenX();
	float getScreenY();

	



	//----------------------------->COLLISION<---------------------------

	bool hit(Object* o);
	Object* hit();

	bool collision(Object* o);
	Object* collision();

	float getCollisionRadius();
	float getCollisionCenterX();
	float getCollisionCenterY();
	float getCollisionCenterZ();
	float intersect(float x, float y, float z, float newX, float newY, float newZ);





private:
	//----------------------------->VARIABLES<--------------------------
	bool	pixelShaderOn;
	bool	vertexShaderOn;

	//-->Animation
	float animFrame;
	float animVelocity;
	float animInterpPercent;
	float animSwitchVelocity;
	
	AnimationClip* currentAnimation;
	AnimationState animationState;
	
	map<char*, AnimationClip*> animations;
};