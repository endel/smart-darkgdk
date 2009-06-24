#pragma once
#include "CommonBSPCollider.h"
#include "ObjectType.h"
#include "Mesh.h"
#include "Image.h"
#include "AnimationClip.h"
#include "DarkGDK.h"
#include <map>
using namespace std;

class VertexShader;
class PixelShader;
class Effect;
class Limb;
class Event;
class Listener;

class Object : 
	public CommonBSPCollider, public Listener
{
public:
	//---------------------->OPERATOR OVERLOADING<----------------------
	bool operator==(Object* o);

	void execute(Event *);
	//------------------->CONSTRUCTORS / DESTRUCTORS<-------------------
	Object(int id);
	Object(char* filename);
	Object(Mesh *m,Image *t);
	Object(float width,float height,float depth);
	Object(ObjectType t, float size);
	Object(Object* second, Limb *l);
	Object(float width, float height);
	Object(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	~Object();
	char* getClassName();





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

	//-->Seta posição do objeto
	void setPosition(float x,float y, float z);
	void setPositionX(float val);
	void setPositionY(float val);
	void setPositionZ(float val);
	void setPosition(Object* o);

	//-->Adiciona posição ao objeto
	void position(float x,float y, float z);
	void positionX(float val);
	void positionY(float val);
	void positionZ(float val);

	//-->Scala objeto
	void scale(float xSize, float ySize, float zSize);
	void scale(float xyz);

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
	void move(float v);
	void moveY(float v);
	void moveX(float v);

	//-->Aponta para objeto
	void lookAt(float x, float y, float z);





	//----------------------------->RENDER<---------------------------
	
	//-->Objeto fica transparente
	void setGhost(bool g=true,int mode=0);

	//-->Seta iluminação
	void setLight(bool l);
	
	//-->Seta cor de luz emissiva
	void setEmissive(int r,int g,int b);

	//-->Seta textura
	void setTexture(Image *t,int mode = -1,int mipGeneration = -1);
	Image *setTexture(char* imagePath,int mode = -1,int mipGeneration = -1);

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

	//-->Show boundingBox
	void showBoundingBox();
	void showBounds(bool boxOnly = false);


	void setColor(int r,int g,int b);
	
	void lock();
	void unlock();
	void toggleLock();
	
	void setSmoothing(float angle);
	void setSmoothing(int percentage);
	void scaleTexture(float u=1, float v=1);
	void scrollTexture(float x, float y);



	//----------------------------->LIMBS<---------------------------
	Limb* addLimb(Object* o);
	void performCheckListForLimbs();





	//----------------------------->GETTERS<---------------------------

	bool  isPlaying();
	bool  isVisible();
	bool  isLooping();
	bool  exists();
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

	//-->Cria box colisao
	void makeBoxCollider(float p_x1, float p_y1, float p_z1, float p_x2, float p_y2, float p_z2);

	//-->Cria box colisao
	void makeBoxCollider();
	
	//-->Habilita colisao
	void collisionEnabled(bool flag);
	
	void setAutomaticCollision(float radius, int response=1);
	void setCollisionType(eCollisionType c);

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
	//----------------------------->FUNCTIONS<--------------------------
	void _init();


	//----------------------------->VARIABLES<--------------------------
	bool	pixelShaderOn;
	bool	vertexShaderOn;
	bool	locked;

	//-->Animation
	float animFrame;
	float animVelocity;
	float animInterpPercent;
	float animSwitchVelocity;
	
	AnimationClip* currentAnimation;
	AnimationState animationState;
	
	map<char*, AnimationClip*> animations;
};