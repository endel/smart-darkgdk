#pragma once

class Sprite :
	public CommonObject
{
public:
	//-->CONSTRUCTORS / DESTRUCTORS
	Sprite(int p_x, int p_y, int p_image);
	Sprite(int p_x, int p_y, int p_image, int p_framesAcross, int p_framesDown, char* name);
	~Sprite();

	
	//-->FUNCTIONS
	void Translate(int p_x, int p_y);
	void Play(int p_start, int p_end, int p_delay);
	
	
	//-->VARIABLES
	int x;
	int y;
	int image;
};
