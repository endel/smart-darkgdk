#pragma once
#include "commonobject.h"
#include "Object.h"
#include "Image.h"

class Limb :
	public CommonObject
{
public:
	Limb(void);
	Limb(Object *linked, Object *top);
	~Limb(void);

	void glueObject(Object* o, int mode=NULL);

	void hide();
	void show();
	void offset( float fX, float fY, float fZ, int iBoundFlag=NULL );
	void rotate( float fX, float fY, float fZ, int iBoundFlag=NULL );
	void scale( float fX, float fY, float fZ, int iBoundFlag=NULL );
	void scale( float fXYZ );
	void link( Object *o );
	void texture( Image *img );
	void texture( int iStage, Image *img );
	void setColor( DWORD dwColor );
	void scrollTexture( float fU, float fV );
	void scaleTexture( float fU, float fV );
	void setSmoothing( float fPercentage );
	void setNormals();

private:
	Object* topObj;
};
