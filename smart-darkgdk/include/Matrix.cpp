#include "Matrix.h"
#include "../Game.h"

Matrix::Matrix(void)
{
}

Matrix::Matrix(float width,float depth,int xsegmented,int zsegmented)
{
	make(width,depth,xsegmented,zsegmented);
}

Matrix::~Matrix(void)
{
	dbDeleteMatrix(this->id);
}
void Matrix::make(float w,float d,int xsegmented,int zsegmented)
{
	this->setId(Game::getMatrixId());
	width = w;
	depth = d;
	dbMakeMatrix(this->id,width,depth,xsegmented,zsegmented);
}

void Matrix::prepareTexture(Image *t,int across,int down)
{
	dbPrepareMatrixTexture(this->id,t->id,across,down);
}
Image* Matrix::prepareTexture(char* imagePath,int across,int down)
{
	Image* t = new Image(imagePath);
	this->prepareTexture(t,across,down);
	return t;
}

void Matrix::setPosition(float x,float y,float z)
{
	dbPositionMatrix(this->id,x,y,z);
}
void Matrix::setPositionX(float n)
{
	dbPositionMatrix(this->id, n, getPositionY(), getPositionZ());
}
void Matrix::setPositionY(float n)
{
	dbPositionMatrix(this->id,getPositionX(), n, getPositionZ());
}
void Matrix::setPositionZ(float n)
{
	dbPositionMatrix(this->id, getPositionX(), getPositionY(), n);
}

void Matrix::fill(float height,int tileNumber)
{
	dbFillMatrix(this->id,height,tileNumber);
}
void Matrix::randomize(int maxHeight)
{
	dbRandomizeMatrix(this->id,maxHeight);
}
void Matrix::setGhost(bool g)
{
	if (g) dbGhostMatrixOn(this->id);
	else dbGhostMatrixOff(this->id);
}
void Matrix::setGhost(bool g,int mode)
{
	if (g) dbGhostMatrixOn(this->id,mode);
	else dbGhostMatrixOff(this->id);
}
void Matrix::setWireframe(bool w)
{
	if (w) dbSetMatrixWireframeOn(this->id);
	else dbSetMatrixWireframeOff(this->id);
}
void Matrix::setImage(int ImageMode,int mipMode)
{
	dbSetMatrixTexture(this->id,ImageMode,mipMode);
}
void Matrix::configure(int wire,int transparency,int cull,int filter,int light,int fog,int ambient)
{
	dbSetMatrix(this->id,wire,transparency,cull,filter,light,fog,ambient);
}
void Matrix::shiftDown()
{
	dbShiftMatrixDown(this->id);
}
void Matrix::shiftLeft()
{
	dbShiftMatrixLeft(this->id);
}
void Matrix::shiftRight()
{
	dbShiftMatrixRight(this->id);
}
void Matrix::shiftUp()
{
	dbShiftMatrixUp(this->id);
}
void Matrix::setHeight(int tileX,int tileZ,float height)
{
	dbSetMatrixHeight(this->id,tileX,tileZ,height);
}
void Matrix::setNormal(int tileX,int tileZ,float nx,int ny, int nz)
{
	dbSetMatrixNormal(this->id,tileX,tileZ,nx,ny,nz);
}
void Matrix::setTile(int tileX,int tileZ,int tileNumber)
{
	dbSetMatrixTile(this->id,tileX,tileZ,tileNumber);
}
void Matrix::update()
{
	return dbUpdateMatrix(this->id);
}

float Matrix::getPositionX()
{
	return dbMatrixPositionX(this->id);
}
float Matrix::getPositionY()
{
	return dbMatrixPositionY(this->id);
}
float Matrix::getPositionZ()
{
	return dbMatrixPositionZ(this->id);
}
int Matrix::tileCount()
{
	return dbMatrixTileCount(this->id);
}
bool Matrix::tilesExist()
{
	return dbMatrixTilesExist(this->id);
}
int Matrix::wireframeState()
{
	return dbMatrixWireframeState(this->id);
}
float Matrix::groundHeight(float x, float z)
{
	return dbGetGroundHeight(this->id,x,z);
}
float Matrix::groundHeight(Object *o)
{
	return this->groundHeight(o->getPositionX(),o->getPositionY());
}
float Matrix::matrixHeight(int tileX,int tileZ)
{
	return dbGetMatrixHeight(this->id,tileX,tileZ);
}

float Matrix::getWidth()
{
	return width;
}
float Matrix::getDepth()
{
	return depth;
}

/*
MATRIX EXIST : Return Integer=MATRIX EXIST(Matrix Number)
MATRIX POSITION X : Return Float=MATRIX POSITION X(Matrix Number)
MATRIX POSITION Y : Return Float=MATRIX POSITION Y(Matrix Number)
MATRIX POSITION Z : Return Float=MATRIX POSITION Z(Matrix Number)
MATRIX TILE COUNT : Return Integer=MATRIX TILE COUNT(Matrix Number)
MATRIX TILES EXIST : Return Integer=MATRIX TILES EXIST(Matrix Number)
MATRIX WIREFRAME STATE : Return Integer=MATRIX WIREFRAME STATE(Matrix Number)
GET GROUND HEIGHT : Return Float=GET GROUND HEIGHT(Matrix Number, X, Z)
GET MATRIX HEIGHT : Return Float=GET MATRIX HEIGHT(Matrix Number, TileX, TileZ)
*/