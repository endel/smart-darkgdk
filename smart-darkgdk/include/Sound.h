#pragma once
#include "CommonSound.h"

class Sound :
	public CommonSound
{
public:
	Sound(void);
	Sound(char* filename,bool is3D=false);
	~Sound(void);

	//setters
	void save(char* filename);
	void clone(Sound* s);
	void play() const;
	void loop() const;
	void stop() const;
	void pause() const;
	void resume() const;
	void position(float x, float y, float z);
	void record();
	void record(int captureDuration);
	void stopRecording();
	void setPan(int pan=127);
	void setSpeed(int frequency) const;
	void setVolume(int volume) const;

	//getters
	int getType();
	bool isPlaying() const;
	bool isLooping() const;
	bool isPaused() const;
	float positionX();
	float positionY();
	float positionZ();
	int getPan();
	int getSpeed() const;
	int getVolume() const;
	float getListenerPositionX();
	float getListenerPositionY();
	float getListenerPositionZ();
	float getListenerAngleX();
	float getListenerAngleY();
	float getListenerAngleZ();

	//statics
	static void setListenerPosition(float x,float y, float z);
	static void setListenerRotation(float x, float y, float z);
	static void setListenerScale(float scale);

};
