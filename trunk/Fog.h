#pragma once

class Fog
{
public:
	Fog(void);
	~Fog(void);
	static void enable();
	static void disable();
	static void setColor(int r,int g,int b);
	static void setDistance(int distance);
	static void setDistance(int start,int end);
};