#include "Game.h"
#include "DarkGDK.h"
#include "include/Core.h"

int Game::OBJECT_ID = 0;
int Game::SPRITE_ID = 0;
int Game::IMAGE_ID = 0;
int Game::MESH_ID = 0;
int Game::LIMB_ID = 0;
int Game::MATRIX_ID = 0;
int Game::MATRIX4_ID = 0;
int Game::LIGHT_ID = 0;
int Game::VERTEXSHADER_ID = 0;
int Game::PIXELSHADER_ID = 0;
int Game::EFFECT_ID = 0;
int Game::MUSIC_ID = 0;
int Game::SOUND_ID = 0;
int Game::PARTICLES_ID = 0;

int Game::CAMERA_ID = -1;

MouseClick Game::LAST_MOUSE_CLICK = NO_CLICK;
MouseClick Game::MOUSE_CLICK = NO_CLICK;
MouseClickState Game::MOUSE_STATE = MOUSE_STANDBY;

void Game::init(char* title,int w,int h,int syncRate) 
{
	dbSetWindowTitle(title);
	
	dbSyncOn( );
	dbSyncRate( syncRate );
	dbRandomize ( dbTimer ( ) );

	Game::setResolution(w,h);
}
void Game::setResolution(int w,int h) {
	dbSetDisplayMode(w, h, 32);
}

//GET IDS
int Game::getObjectId() {
	return ++OBJECT_ID;
}
int Game::getSpriteId()
{
	return ++SPRITE_ID;
}
int Game::getImageId(){
	return ++IMAGE_ID;
}
int Game::getMeshId() {
	return ++MESH_ID;
}
int Game::getLimbId()
{
	return ++LIMB_ID;
}
int Game::getMatrixId() {
	return ++MATRIX_ID;
}
int Game::getMatrix4Id()
{
	return ++MATRIX4_ID;
}
int Game::getCameraId() {
	return ++CAMERA_ID;
}
int Game::getLightId() {
	return ++LIGHT_ID;
}
int Game::getVertexShaderId()
{
	return ++VERTEXSHADER_ID;
}
int Game::getPixelShaderId()
{
	return ++PIXELSHADER_ID;
}
int Game::getEffectId()
{
	return ++EFFECT_ID;
}
int Game::getMusicId()
{
	return ++MUSIC_ID;
}
int Game::getSoundId()
{
	return ++SOUND_ID;
}
int Game::getParticlesId()
{
	return ++PARTICLES_ID;
}

int Game::width()
{
	return dbScreenWidth();
}
int Game::height()
{
	return dbScreenHeight();
}
bool Game::loop()
{
	if (MOUSE_STATE == MOUSE_PRESSING) 
	{
		LAST_MOUSE_CLICK = NO_CLICK;
	}
	if (MOUSE_CLICK == NO_CLICK && MOUSE_STATE != MOUSE_STANDBY) 
	{
		MOUSE_STATE = MOUSE_STANDBY;
	}
	return LoopGDK();
}
void Game::refresh()
{
	MOUSE_CLICK = (MouseClick) dbMouseClick();
	

	if (MOUSE_CLICK != LAST_MOUSE_CLICK && MOUSE_STATE != MOUSE_PRESSING) 
	{
		MOUSE_STATE = MOUSE_PRESS;
		LAST_MOUSE_CLICK = MOUSE_CLICK;
	} else
	{
		MOUSE_STATE = MOUSE_PRESSING;
	}
	dbSync();
}
void Game::setDir(char* dir)
{
	dbSetDir(dir);
}
void Game::setBackdropColor(int r,int g,int b)
{
	dbBackdropColor(dbRGB(r,g,b));
}
MouseClick Game::getLastMouseClick()
{
	return LAST_MOUSE_CLICK;
}