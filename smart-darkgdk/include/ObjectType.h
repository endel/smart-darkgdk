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

//-->AnimationState = Controla estado de anima��o que o Object esta no momento
enum AnimationState
{
	STOPPED, //->Parado em determinado frame
	PLAYING, //->Alguma anima��o rolando
	CHANGING //->Fade entre duas anima��es
};

//-->WrapMode = Modos de anima��o dos AnimationClip
enum WrapMode
{
	ONCE, //->Toca a anima��o uma vez e para no ultimo frame
	LOOP  //->Fica em loop na anima��o
};