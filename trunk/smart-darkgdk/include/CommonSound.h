#pragma once
#include "commonobject.h"

class CommonSound
	: public CommonObject
{
public:
	CommonSound(void);
	~CommonSound(void);
	virtual void play() const=0;
	virtual void loop() const=0;
	virtual void stop() const=0;
	virtual void pause() const=0;
	virtual void resume() const=0;
	virtual void setSpeed(int frequency) const=0;
	virtual void setVolume(int volume) const=0;

	virtual bool isPlaying() const=0;
	virtual bool isLooping() const=0;
	virtual bool isPaused() const=0;
	virtual int getSpeed() const=0;
	virtual int getVolume() const=0;
};
