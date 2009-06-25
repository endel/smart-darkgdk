#include "Commonobject.h"

#include "../Game.h"
#include "Sprite.h"
#include "DarkGDK.h"


Sprite::Sprite(char* filename, int x, int y)
{
	this->setId(Game::getSpriteId());
	
	Image* img = new Image(filename);
	dbSprite(this->id, x, y, img->id);

	resetTextureOffset();
}

Sprite::Sprite(int n)
{
	setId(n);
}

//--
Sprite::Sprite(int p_x, int p_y, Image* p_image)
{
	this->setId(Game::getSpriteId());

	dbSprite(this->id, 0, 0, p_image->id);
	dbOffsetSprite(this->id, p_x, p_y);

	resetTextureOffset();
}
//--
Sprite::Sprite(int p_x, int p_y, Image* p_image, int p_framesAcross, int p_framesDown, char* name)
{
	this->setId(Game::getSpriteId());

	dbCreateAnimatedSprite(this->id, name, p_framesAcross, p_framesDown, p_image->id);
	dbSprite(this->id, p_x, p_y, p_image->id);

	resetTextureOffset();
}
//--

Sprite::Sprite(char* filename, char* animation_name, int p_framesAcross, int p_framesDown)
{
	this->setId(Game::getSpriteId());

	Image* img = new Image(filename);
	dbCreateAnimatedSprite(this->id, animation_name, p_framesAcross, p_framesDown, img->id);

	resetTextureOffset();
}


//--
Sprite::~Sprite(void)
{
	dbDeleteSprite(this->id);
}

void Sprite::resetTextureOffset()
{
	this->offsetTextureU = 0;
	this->offsetTextureV = 0;
}


void Sprite::load(char* filename, int x, int y)
{
	this->setId(Game::getSpriteId());
	
	Image* img = new Image(filename);
	dbSprite(this->id, x, y, img->id);

	resetTextureOffset();
}


//------------------------------------------------
//					TRANSFORM
//------------------------------------------------

void
Sprite::position(int p_x, int p_y)
{
	dbOffsetSprite(this->id, -p_x, -p_y);
}
//--

void
Sprite::translate(int p_x, int p_y)
{
	dbOffsetSprite(this->id, dbSpriteOffsetX(this->id) - p_x, dbSpriteOffsetY(this->id) - p_y);
}
//--

void
Sprite::rotation(float p_angle)
{
	dbRotateSprite(this->id, p_angle);
}
//--

void
Sprite::rotate(float p_angle)
{
	dbRotateSprite(this->id, dbSpriteAngle(this->id) + p_angle);
}
//--

void
Sprite::scale(int p_x, int p_y)
{
	dbSizeSprite(this->id, p_x, p_y);
}
//--

void
Sprite::mirror(bool p_x, bool p_y)
{
	if(p_x) dbMirrorSprite(this->id);
	if(p_y) dbFlipSprite(this->id);
}
//--







//------------------------------------------------
//					VISIBILITY
//------------------------------------------------

void
Sprite::play(int p_start, int p_end, int p_delay)
{
	dbPlaySprite(this->id, p_start, p_end, p_delay);
}
//--

void
Sprite::changeImage(Image* p_image)
{
	dbSetSpriteImage(this->id, p_image->id);
}
//--

void
Sprite::offsetTexture(float p_offestU, float p_offsetV, float p_velocity)
{
	offsetTextureU += p_offestU * p_velocity;
	offsetTextureV += p_offsetV * p_velocity;

	dbSetSpriteTextureCoord(this->id, 0, 0 + offsetTextureU, 0 + offsetTextureV);
	dbSetSpriteTextureCoord(this->id, 1, 1 + offsetTextureU, 0 + offsetTextureV);
	dbSetSpriteTextureCoord(this->id, 2, 0 + offsetTextureU, 1 + offsetTextureV);
	dbSetSpriteTextureCoord(this->id, 3, 1 + offsetTextureU, 1 + offsetTextureV);
}
//--

void
Sprite::color(int p_r, int p_g, int p_b)
{
	dbSetSpriteDiffuse(this->id, p_r, p_g, p_b);
}
//--

void
Sprite::show()
{
	dbShowSprite(this->id);
}
//--
void
Sprite::hide()
{
	dbHideSprite(this->id);
}
//--
void
Sprite::toggle()
{
	if (isVisible()) hide();
	else show();
}





//------------------------------------------------
//					GETTERS
//------------------------------------------------


Sprite* Sprite::hit()
{
	return new Sprite( dbSpriteHit(this->id, 0) );
}
Sprite* Sprite::collision()
{
	return new Sprite( dbSpriteCollision(this->id, 0) );
}

bool Sprite::hit(Sprite *s)
{
	return (bool) dbSpriteHit(this->id, s->id);
}
bool Sprite::collision(Sprite *s)
{
	return (bool) dbSpriteCollision(this->id, s->id);
}


bool Sprite::exists()
{
	return dbSpriteExist(this->id);
}

int
Sprite::getPositionX()
{
	return dbSpriteOffsetX(this->id);
}
//--

int
Sprite::getPositionY()
{
	return dbSpriteOffsetY(this->id);
}
//--

int
Sprite::getWidth()
{
	return dbSpriteWidth(this->id);
}
//--

int
Sprite::getHeight()
{
	return dbSpriteHeight(this->id);
}
//--

float
Sprite::getAngle()
{
	return dbSpriteAngle(this->id);
}
//--

int
Sprite::isVisible()
{
	return dbSpriteVisible(this->id);
}
//--

int
Sprite::getColorR()
{
	return dbSpriteRed(this->id);
}
//--

int
Sprite::getColorG()
{
	return dbSpriteGreen(this->id);
}
//--

int
Sprite::getColorB()
{
	return dbSpriteBlue(this->id);
}
//--





