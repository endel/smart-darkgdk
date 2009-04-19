#include "Sound.h"
#include "Game.h"

Sound::Sound(void)
{
}
Sound::Sound(char* filename,bool is3D)
{
	this->setId(Game::getSoundId());
	if (is3D) dbLoad3DSound(filename,this->id);
	else dbLoadSound(filename,is3D);
}
Sound::~Sound(void)
{
	dbDeleteSound(this->id);
}
//setters
void Sound::save(char* filename)
{
	dbSaveSound(filename,this->id);
}
void Sound::clone(Sound* s)
{
	dbCloneSound(this->id,s->id);
}
void Sound::play() const
{
	dbPlaySound(this->id);
}
void Sound::loop() const
{
	dbLoopSound(this->id);
}
void Sound::stop() const
{
	dbStopSound(this->id);
}
void Sound::pause() const
{
	dbPauseSound(this->id);
}
void Sound::resume() const
{
	dbResumeSound(this->id);
}
void Sound::position(float x, float y, float z)
{
	dbPositionSound(this->id,x,y,z);
}
void Sound::record()
{
	dbRecordSound(this->id);
}
void Sound::record(int captureDuration)
{
	dbRecordSound(this->id,captureDuration);
}
void Sound::stopRecording()
{
	dbStopRecordingSound();
}
void Sound::setPan(int pan)
{
	dbSetSoundPan(this->id,pan);
}
void Sound::setSpeed(int frequency) const
{
	dbSetSoundSpeed(this->id,frequency);
}
void Sound::setVolume(int volume) const
{
	dbSetSoundVolume(this->id, volume);
}

//getters
int Sound::getType()
{
	return dbSoundType(this->id);
}
bool Sound::isPlaying() const
{
	return dbSoundPlaying(this->id);
}
bool Sound::isLooping() const
{
	return dbSoundLooping(this->id);
}
bool Sound::isPaused() const
{
	return dbSoundPaused(this->id);
}
float Sound::positionX()
{
	return dbSoundPositionX(this->id);
}
float Sound::positionY()
{
	return dbSoundPositionY(this->id);
}
float Sound::positionZ()
{
	return dbSoundPositionZ(this->id);
}
int Sound::getPan()
{
	return dbSoundPan(this->id);
}
int Sound::getSpeed() const
{
	return dbSoundSpeed(this->id);
}
int Sound::getVolume() const
{
	return dbSoundVolume(this->id);
}

float Sound::getListenerPositionX()
{
	return dbGetListenerPositionX(this->id);
}
float Sound::getListenerPositionY()
{
	return dbGetListenerPositionY(this->id);
}
float Sound::getListenerPositionZ()
{
	return dbGetListenerPositionZ(this->id);
}
float Sound::getListenerAngleX()
{
	return dbGetListenerAngleX(this->id);
}
float Sound::getListenerAngleY()
{
	return dbGetListenerAngleY(this->id);
}
float Sound::getListenerAngleZ()
{
	return dbGetListenerAngleZ(this->id);
}

//statics
void Sound::setListenerPosition(float x,float y, float z)
{
	dbPositionListener(x,y,z);
}
void Sound::setListenerRotation(float x, float y, float z)
{
	dbRotateListener(x,y,z);
}
void Sound::setListenerScale(float scale)
{
	dbScaleListener(scale);
}