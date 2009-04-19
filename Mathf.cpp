#include "Mathf.h"

int
Mathf::Lerp(const int p_initialValue, const int p_finalValue, float ratio)
{
	return (int)((1.0f - ratio) * p_initialValue + ratio * p_finalValue);
}

float
Mathf::Lerp(const float p_initialValue, const float p_finalValue, float ratio)
{
	return ((1.0f - ratio) * p_initialValue + ratio * p_finalValue);
}