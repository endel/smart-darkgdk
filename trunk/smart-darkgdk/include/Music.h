#pragma once
#include "commonsound.h"

class Music :
	public CommonSound
{
public:
	Music(void);
	Music(char* filename);
	Music(int cdTrack);
	~Music(void);
	
	//setters
	void play() const;
	void loop() const;
	void stop() const;
	void pause() const;
	void resume() const;
	void setSpeed(int frequency) const;
	void setVolume(int volume) const;

	//getters
	bool isPlaying() const;
	bool isLooping() const;
	bool isPaused() const;
	int getSpeed() const;
	int getVolume() const;
	static int getNumberOfCDTracks();

};
