#pragma once
#include "ObjectType.h"

class AnimationClip
{
public:
	//-->CONSTRUCTOR / DESTRUCTOR
	AnimationClip(char* p_name, int p_frameInicial, int p_frameFinal, int p_velocidade, WrapMode p_wrapMode);
	AnimationClip(AnimationClip* animation);

	//-->VARIABLES
	char* name;
	int frameInicial;
	int frameFinal;
	int velocidade;

	WrapMode wrapMode;
};
