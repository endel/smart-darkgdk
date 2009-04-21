#pragma once

class Mathf
{
public:
	//-->STATIC FUNCTIONS
	static int   Lerp (const int p_initialValue, const int p_finalValue, float ratio);
	static int   Lerp (const int p_initialValue, const int p_finalValue, float ratio, float* transition);
	static float Lerp (const float p_initialValue, const float p_finalValue, float ratio);
	static float Lerp (const float p_initialValue, const float p_finalValue, float ratio, float* transition);

	static float Clamp(float value, float min, float max);
	static int   Clamp(int value, int min, int max);
};
