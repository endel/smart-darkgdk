#pragma once

class String
{
public:
	String(void);
	~String(void);
	
	//setters
	static void draw(int x,int y,char* string);
	static void draw(int x,int y,int val);
	static void draw(int x,int y,float val);
	static void draw3D(char* string);
	static void setColor(int alpha,int r,int g,int b);
	static void setFont(char* typeface);
	static void setOpaque();
	static void setSize(int size);
	static void setToBold();
	static void setToBoldItalic();
	static void setToItalic();
	static void setToNormal();
	static void setToOpaque();
	static void setToTransparent();
	static void setTransparent();

	//getters
	static char* convert(int v);
	static char* convert(float v);
	static int ascii(char * c);
	static char* bin(int v);
	static char* chr(int ascii);
	static char* hex(int i);
	static char* left(char* c,int offset);
	static int length(char* string);
	static char* toLower(char* string);
	static char* toUpper(char* string);
	static char* mid(char* string,int q);
	static char* right(char* c,int offset);
	static float toFloat(char* c);
	static char* spaces(int num);
};
