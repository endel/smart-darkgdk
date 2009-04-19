#include "Fog.h"
#include "DarkGDK.h"

Fog::Fog(void)
{
}

Fog::~Fog(void)
{
}
void Fog::enable()
{
	dbFogOn();
}
void Fog::disable()
{
	dbFogOff();
}
void Fog::setColor(int r,int g,int b)
{
	dbFogColor(r,g,b);
}
void Fog::setDistance(int distance)
{
	dbFogDistance(distance);
}
void Fog::setDistance(int start,int end)
{
	dbFogDistance(start,end);
}
//dbFogAvailable
//dbFogRangeAvailable
//dbFogTableAvailable
//dbFogVertexAvailable