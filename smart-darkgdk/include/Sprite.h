#pragma once

#include "Image.h"

class Sprite :
	public CommonObject
{
public:

	//-->CONSTRUCTORS / DESTRUCTORS
	Sprite(void);
	Sprite(int n);
	Sprite(char* filename, int x=0, int y=0);
	Sprite(char* filename, char* animation_name, int p_framesAcross, int p_framesDown);
	Sprite(int p_x, int p_y, Image* p_image);
	Sprite(int p_x, int p_y, Image* p_image, int p_framesAcross, int p_framesDown, char* name);
	~Sprite();
	void resetTextureOffset();

	void load(char* filename, int x=0, int y=0);

	
	//-->TRANFORM
	void position(int p_x, int p_y);
	void translate(int p_x, int p_y);
	void rotation(float p_angle);
	void rotate(float p_angle);
	void scale(int p_x, int p_y);
	void mirror(bool p_x, bool p_y);



	//-->VISIBILITY
	void play(int p_start, int p_end, int p_delay);
	void changeImage(Image* p_image);
	void offsetTexture(float p_offestU, float p_offsetV, float p_velocity);
	void color(int p_r, int p_g, int p_b);

	void show();
	void hide();
	void toggle();



	//-->GETTERS
	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHeight();
	float getAngle();
	int isVisible();
	int getColorR();
	int getColorG();
	int getColorB();
	bool exists();

	Sprite* hit();
	Sprite* collision();

	bool hit(Sprite *s);
	bool collision(Sprite *s);


	//-->VARIABLES
	float offsetTextureU;
	float offsetTextureV;
	
};
