#pragma once
#include "CommonBSPCollider.h"
#include "Image.h"
#include "ObjectType.h"

class Texture;
class Object;

class Camera :
	public CommonBSPCollider
{
public:
	//------------------->CONSTRUCTORS / DESTRUCTORS<-------------------
	Camera();
	Camera(int n);
	Camera(int fov, int nearClip, int farClip);
	~Camera(void);
	char* getClassName();



	//------------------->FUNCTIONS<-------------------
	//-->Set current camera
	static void setCurrentCamera(Camera* camera);

	//-->Seta FOV (Abertura da lenta)
	void setFov(float fov);

	//-->Seta FarClip e NearClip
	void setClips(float nearClip, float farClip);

	//-->Limpa tela
	void clearView(int r,int g,int b);

	//-->Seta cor de fundo
	void backDropColor(int r, int g, int b);





	//------------------->TRANSFORM<-------------------

	//-->Move camera globalmente
	void globalMove(float x,float y, float z);

	//-->Move camera localmente
	void localMove(float x,float y, float z);

	//-->PosicionaCamera
	void position(float x,float y, float z);
	void position(Object *o);

	//-->Aponta para cordenadas
	void lookAt(float x,float y, float z);
	void point(float x, float y, float z);

	//-->Rotaciona tantos graus
	void rotate(float angleX,float angleY,float angleZ);

	//-->Rotaciona tantos graus
	void setRotation(float angleX,float angleY,float angleZ);
	void setRotation(Object *o);

	//-->Rotaciona no eixo Y
	void turn(float q);

	//-->Follow Object 3D Person
	void follow3DPerson(Object* objeto, float distance, float height, float alturaVisao);

	//-->Controlar com as setas do teclado: Utilizada para debuggar o cenário.
	void controlUsingArrowKeys(float velocity=1,float turnSpeed=1);

	//-->Seta a orientacao igual ao objeto
	void setToObjectOrientation(Object *o);

	

	void setView(float left,float top,float right,float bottom);
	void setToFollow(float x,float y,float z,float angle,float distance, float height,float smooth, int collision);
	void setToFollow(Object* o,ANGLE a,float distance, float height,float smooth, int collision);
	void setToImage(Image *t,int width,int height);
	void setToImage(Image *t,int width,int height,int genAlpha);


	//------------------->GETTERS<-------------------

	float getPositionX();
	float getPositionY();
	float getPositionZ();
	float getAngleX();
	float getAngleY();
	float getAngleZ();
	float getDirectionX();
	float getDirectionY();
	float getDirectionZ();
};
