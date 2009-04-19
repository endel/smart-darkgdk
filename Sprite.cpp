#include "Commonobject.h"
#include "Game.h"
#include "Sprite.h"
#include "DarkGDK.h"

Sprite::Sprite(int p_x, int p_y, int p_image)
{
	this->setId(Game::getSpriteId());

	dbSprite(this->id, p_x, p_y, p_image);
}
//--
Sprite::Sprite(int p_x, int p_y, int p_image, int p_framesAcross, int p_framesDown, char* name)
{
	this->setId(Game::getSpriteId());

	dbCreateAnimatedSprite(this->id, name, p_framesAcross, p_framesDown, p_image);
	dbSprite(this->id, p_x, p_y, p_image);
}
//--
Sprite::~Sprite(void)
{
}




void
Sprite::Translate(int p_x, int p_y)
{
	x += p_x;
	y += p_y;
}

void
Sprite::Play(int p_start, int p_end, int p_delay)
{
	dbPlaySprite(this->id, p_start, p_end, p_delay);
}