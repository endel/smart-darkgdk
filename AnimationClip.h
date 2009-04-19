#pragma once

class AnimationClip
{
public:
	//-->CONSTRUCTOR / DESTRUCTOR
	AnimationClip(char* p_name, int p_frameInicial, int p_frameFinal, int p_velocidade);

	//-->VARIABLES
	char* name;
	int frameInicial;
	int frameFinal;
	int velocidade;
};
