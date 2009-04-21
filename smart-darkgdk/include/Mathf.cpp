#include "Mathf.h"

//------------------------------------------------
//					STATIC FUNCTIONS
//------------------------------------------------

int
Mathf::Lerp(const int p_initialValue, const int p_finalValue, float ratio)
{
	ratio = Clamp(ratio, 0.0f, 1.0f);

	return (int)((1.0f - ratio) * p_initialValue + ratio * p_finalValue);
}
//--

int
Mathf::Lerp(const int p_initialValue, const int p_finalValue, float ratio, float* transition)
{
	ratio = Clamp(ratio, 0.0f, 1.0f);

	ratio = ((ratio * ratio * ratio * ratio * ratio * transition[0]) + (ratio * ratio * ratio * ratio * transition[1]) + (ratio * ratio * ratio * transition[2]) + (ratio * ratio * transition[3]) + (ratio * transition[4]));
	return (int)((1.0f - ratio) * p_initialValue + ratio * p_finalValue);
}
//--

float
Mathf::Lerp(const float p_initialValue, const float p_finalValue, float ratio)
{
	ratio = Clamp(ratio, 0.0f, 1.0f);

	return ((1.0f - ratio) * p_initialValue + ratio * p_finalValue);
}
//--

float
Mathf::Lerp(const float p_initialValue, const float p_finalValue, float ratio, float* transition)
{
	ratio = Clamp(ratio, 0.0f, 1.0f);

	ratio = ((ratio * ratio * ratio * ratio * ratio * transition[0]) + (ratio * ratio * ratio * ratio * transition[1]) + (ratio * ratio * ratio * transition[2]) + (ratio * ratio * transition[3]) + (ratio * transition[4]));
	return ((1.0f - ratio) * p_initialValue + ratio * p_finalValue);
}
//--

float
Mathf::Clamp(float value, float min, float max)
{
	if(value > max)	value = max;
	if(value < min) value = min;

	return value;
}
//--

int
Mathf::Clamp(int value, int min, int max)
{
	if(value > max)	value = max;
	if(value < min) value = min;

	return value;
}