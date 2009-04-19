#include "Particles.h"
#include "Game.h"

Particles::Particles(void)
{
}

Particles::Particles(Image *t, int frequency, float radius)
{
	this->setId(Game::getParticlesId());
	dbMakeParticles(this->id,t->id,frequency,radius);
}

Particles::Particles(ParticleType p, Image *t, int frequency, float x, float y, float z, float width, float height, float depth)
{
	this->setId(Game::getParticlesId());
	switch (p)
	{
		case SNOW: dbMakeSnowParticles(this->id,t->id,frequency,x,y,z,width,height,depth);break;
		case FIRE: dbMakeFireParticles(this->id,t->id,frequency,x,y,z,width,height,depth);break;
	}
}

Particles::~Particles(void)
{
	dbDeleteParticles(this->id);
}

void Particles::show()
{
	visible = true;
	dbShowParticles(this->id);
}
void Particles::hide()
{
	visible = false;
	dbHideParticles(this->id);
}
void Particles::toggle()
{
	if (visible) hide();
	else show();
}
void Particles::position(float x,float y,float z)
{
	dbPositionParticles(this->id,x,y,z);
}
void Particles::positionEmissions(float x,float y,float z)
{
	dbPositionParticleEmissions(this->id,x,y,z);
}
void Particles::rotate(float x,float y,float z)
{
	dbRotateParticles(this->id,x,y,z);
}
void Particles::setColor(int r,int g,int b)
{
	dbColorParticles(this->id,r,g,b);
}
void Particles::setEmissions(int frequency)
{
	dbSetParticleEmissions(this->id,frequency);
}
void Particles::setGravity(float value)
{
	dbSetParticleGravity(this->id,value);
}
void Particles::setSpeed(int secondsPerFrame)
{
	dbSetParticleSpeed(this->id,secondsPerFrame);
}
void Particles::setChaos(float value)
{
	dbSetParticleChaos(this->id,value);
}
void Particles::setFloor(int flag)
{
	dbSetParticleFloor(this->id,flag);
}
void Particles::setLife(int percentage)
{
	dbSetParticleLife(this->id,percentage);
}
void Particles::setGhost(int ghostMode)
{
	dbGhostParticlesOn(this->id,ghostMode);
}
void Particles::setGhost(bool disable)
{
	if (!disable) dbGhostParticlesOff(this->id);
	else setGhost(1);
}

float Particles::positionX()
{
	return dbParticlesPositionX(this->id);
}
float Particles::positionY()
{
	return dbParticlesPositionY(this->id);
}
float Particles::positionZ()
{
	return dbParticlesPositionZ(this->id);
}