#include "AnimationClip.h"

AnimationClip::AnimationClip(char* p_name, int p_frameInicial, int p_frameFinal, int p_velocidade, WrapMode p_wrapMode)
{
	name		 = p_name;
	frameInicial = p_frameInicial;
	frameFinal   = p_frameFinal;
	velocidade   = p_velocidade;
	wrapMode     = p_wrapMode;
}
//--

AnimationClip::AnimationClip(AnimationClip* animation)
{
	name		 = animation->name;
	frameInicial = animation->frameInicial;
	frameFinal   = animation->frameFinal;
	velocidade   = animation->velocidade;
	wrapMode     = animation->wrapMode;
}
