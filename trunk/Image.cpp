#include "Image.h"
#include "Game.h"

Image::Image(void)
{
}
Image::Image(char* filename)
{
	this->setId(Game::getImageId());
	dbLoadImage(filename,this->id);
}
Image::Image(char* filename,int flag)
{
	this->setId(Game::getImageId());
	dbLoadImage(filename,this->id,flag);
}
Image::Image(char* filename,int flag,int divideSize)
{
	this->setId(Game::getImageId());
	dbLoadImage(filename,this->id,flag,divideSize);
}

Image::~Image(void)
{
	dbDeleteImage(this->id);
}

void Image::setColorkey(int r,int g,int b)
{
	dbSetImageColorKey(r,g,b);
}
bool Image::exist()
{
	return dbImageExist(this->id);
}