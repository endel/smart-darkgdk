#include "AnimationClip.h"

AnimationClip::AnimationClip(char* p_name, int p_frameInicial, int p_frameFinal, int p_velocidade)
{
	name		 = p_name;
	frameInicial = p_frameInicial;
	frameFinal   = p_frameFinal;
	velocidade   = p_velocidade;
}

