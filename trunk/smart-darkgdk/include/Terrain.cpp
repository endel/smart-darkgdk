#include "Terrain.h"
#include "../Game.h"
#include "Image.h"
#include "Object.h"

Terrain::Terrain()
{
	setId(Game::getTerrainId());
	setup();
	dbMakeObjectTerrain(this->id);
	
}

Terrain::~Terrain(void)
{

}

void Terrain::load(char *filename)
{
	dbLoadTerrain(filename, this->id);
}
void Terrain::save(char *filename)
{
	dbSaveTerrain(filename, this->id);
}

void Terrain::setup()
{
	dbSetupTerrain();
}
void Terrain::build()
{
	dbBuildTerrain(this->id);
}
void Terrain::update()
{
	dbUpdateTerrain();
}

void Terrain::setScale(float x, float y, float z)
{
	dbSetTerrainScale(this->id, x, y, z);
}
void Terrain::setSplit(int split)
{
	dbSetTerrainSplit(this->id, split);
}
void Terrain::setTiling(int tile)
{
	dbSetTerrainTiling(this->id, tile);
}
void Terrain::setHeightmap(char* filename)
{
	dbSetTerrainHeightmap(this->id, filename);
}

void Terrain::setTexture(Image *texture, int detail)
{
	dbSetTerrainTexture(this->id, texture->id, detail);

}
Image *Terrain::setTexture(char* imagePath, int detail)
{
	Image* t = new Image(imagePath);
	this->setTexture(t);
	return t;
}


void Terrain::setLight( float fXDir, float fYDir, float fZDir, int iRed, int iGreen, int iBlue, float fScale )
{
	dbSetTerrainLight(this->id, fXDir, fYDir, fZDir, iRed, iGreen, iBlue, fScale);
}

float Terrain::getGroundHeight(float x, float z)
{
	return dbGetTerrainGroundHeight(this->id, x, z);
}


float Terrain::getGroundHeight(Object *o)
{
	return dbGetTerrainGroundHeight(this->id, o->getPositionX(), o->getPositionZ());
}


float Terrain::getXSize()
{
	return dbGetTerrainXSize(this->id);
}

float Terrain::getZSize()
{
	return dbGetTerrainZSize(this->id);
}
