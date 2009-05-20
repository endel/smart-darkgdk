#include "DarkGDK.h"
#include "Limb.h"
#include "Mesh.h"
#include "Image.h"
#include "Object.h"
#include "../Game.h"

Limb::Limb(void)
{
	setId(Game::getLimbId());
}

Limb::Limb(Object* linked, Object* top)
{
	setId(Game::getLimbId());
	topObj = top;

	Mesh *m = new Mesh(linked);
	delete linked;

	dbAddLimb( topObj->id, this->id, m->id);
}

void Limb::glueObject(Object* o, int mode)
{
	if (mode)
	{
		dbGlueObjectToLimb( topObj->id, o->id, this->id);
	} else {
		dbGlueObjectToLimb( topObj->id, o->id, this->id, mode);
	}
}

Limb::~Limb(void)
{
	dbRemoveLimb( topObj->id, this->id);
}


void Limb::hide()
{
	dbHideLimb(topObj->id,this->id);
}
void Limb::show()
{
	dbShowLimb( topObj->id, this->id );
}
void Limb::offset( float fX, float fY, float fZ, int iBoundFlag )
{
	if (iBoundFlag) {
		dbOffsetLimb( topObj->id, this->id, fX, fY, fZ, iBoundFlag );
	} else {
		dbOffsetLimb( topObj->id, this->id, fX, fY, fZ );
	}
}

void Limb::rotate( float fX, float fY, float fZ, int iBoundFlag )
{
	if (iBoundFlag) {
		dbRotateLimb( topObj->id, this->id, fX, fY, fZ, iBoundFlag );
	} else {
		dbRotateLimb( topObj->id, this->id, fX, fY, fZ );
	}
}
void Limb::scale( float fX, float fY, float fZ, int iBoundFlag )
{
	if (iBoundFlag) {
		dbScaleLimb( topObj->id, this->id, fX, fY, fZ, iBoundFlag );
	} else {
		dbScaleLimb( topObj->id, this->id, fX, fY, fZ );
	}
}
void Limb::link( Object *o )
{
	dbLinkLimb( topObj->id, o->id, this->id );
}
void Limb::texture( Image *img )
{
	dbTextureLimb( topObj->id, this->id, img->id );
}
void Limb::texture( int iStage, Image *img )
{
	dbTextureLimb( topObj->id, this->id, iStage, img->id );
}
void Limb::setColor( DWORD dwColor )
{
	dbColorLimb( topObj->id, this->id, dwColor );
}
void Limb::scrollTexture( float fU, float fV )
{
	dbScrollLimbTexture( topObj->id, this->id, fU, fV );
}
void Limb::scaleTexture( float fU, float fV )
{
	dbScaleLimbTexture( topObj->id, this->id, fU, fV );
}
void Limb::setSmoothing( float fPercentage )
{
	dbSetLimbSmoothing( topObj->id, this->id, fPercentage );
}
void Limb::setNormals()
{
	dbSetLimbNormals( topObj->id, this->id );
}