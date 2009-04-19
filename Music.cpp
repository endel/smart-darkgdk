#include "Music.h"
#include "Game.h"

Music::Music(void)
{
}

Music::Music(char* filename)
{
	this->setId(Game::getMusicId());
	dbLoadMusic(filename,this->id);
}
Music::Music(int cdTrack)
{
	this->setId(Game::getMusicId());
	dbLoadCDMusic(cdTrack,this->id);
}

Music::~Music(void)
{
	dbDeleteMusic(this->id);
}


//setters
void Music::play() const
{
	dbPlayMusic(this->id);
}
void Music::loop() const
{
	dbLoopMusic(this->id);
}
void Music::stop() const
{
	dbStopMusic(this->id);
}
void Music::pause() const
{
	dbPauseMusic(this->id);
}
void Music::resume() const
{
	dbResumeMusic(this->id);
}
void Music::setSpeed(int speed) const
{
	dbSetMusicSpeed(this->id,speed);
}
void Music::setVolume(int volume) const
{
	dbSetMusicVolume(this->id,volume);
}

//getters
bool Music::isPlaying() const
{
	return dbMusicPlaying(this->id);
}
bool Music::isLooping() const
{
	return dbMusicLooping(this->id);
}
bool Music::isPaused() const
{
	return dbMusicPaused(this->id);
}
int Music::getSpeed() const
{
	return dbMusicSpeed(this->id);
}
int Music::getVolume() const
{
	return dbMusicVolume(this->id);
}
int Music::getNumberOfCDTracks()
{
	return dbGetNumberOfCDTracks();
}
