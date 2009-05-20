#pragma once

enum ObjectType 
{
	BOX,
	CONE,
	CUBE,
	CYLINDER,
	PLAIN,
	SPHERE,
	TRIANGLE
};

enum ParticleType 
{
	SNOW,
	FIRE
};

enum ANGLE 
{
	ANGLE_X,
	ANGLE_Y,
	ANGLE_Z
};

//-->AnimationState = Controla estado de animação que o Object esta no momento
enum AnimationState
{
	STOPPED, //->Parado em determinado frame
	PLAYING, //->Alguma animação rolando
	CHANGING //->Fade entre duas animações
};

//-->WrapMode = Modos de animação dos AnimationClip
enum WrapMode
{
	ONCE, //->Toca a animação uma vez e para no ultimo frame
	LOOP  //->Fica em loop na animação
};