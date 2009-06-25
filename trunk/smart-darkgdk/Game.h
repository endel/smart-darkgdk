#pragma once
#include "DarkGDK.h"

//definitions
#include "include/ObjectType.h"
#include "include/Core.h"

//classes
#include "include/CommonObject.h"
#include "include/Sprite.h"
#include "include/Camera.h"
#include "include/Image.h"
#include "include/Mesh.h"
#include "include/Limb.h"
#include "include/Matrix.h"
#include "include/Matrix4.h"
#include "include/Object.h"
#include "include/Light.h"
#include "include/Effect.h"
#include "include/PixelShader.h"
#include "include/VertexShader.h"
#include "include/Music.h"
#include "include/Sound.h"
#include "include/Particles.h"
#include "include/Sprite.h"
#include "include/Terrain.h"


//smart classes
#include "include/Lives.h"

//static classes
#include "include/BSP.h"
#include "include/Key.h"
#include "include/String.h"
#include "include/Mouse.h"
#include "include/Joystick.h"
#include "include/Fog.h"
#include "include/FTP.h"
#include "include/Mathf.h"
#include "include/Transition.h"

//std classes
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define random(x)	dbRnd(x)
#define SIN(x)		sin((double)(x))
#define COS(x)		cos((double)(x))

//game
class Game
{
public:
	//public vars
	static int OBJECT_ID;
	static int SPRITE_ID;
	static int IMAGE_ID;
	static int LIMB_ID;
	static int MESH_ID;
	static int MATRIX_ID;
	static int MATRIX4_ID;
	static int CAMERA_ID;
	static int LIGHT_ID;
	static int VERTEXSHADER_ID;
	static int PIXELSHADER_ID;
	static int EFFECT_ID;
	static int MUSIC_ID;
	static int SOUND_ID;
	static int PARTICLES_ID;
	static int TERRAIN_ID;

	static MouseClickState MOUSE_STATE;
	static MouseClick LAST_MOUSE_CLICK;
	static MouseClick MOUSE_CLICK;


	//public methods
	Game(void);
	static int getObjectId();
	static int getSpriteId();
	static int getImageId();
	static int getMeshId();
	static int getLimbId();
	static int getMatrixId();
	static int getMatrix4Id();
	static int getCameraId();
	static int getLightId();
	static int getVertexShaderId();
	static int getPixelShaderId();
	static int getEffectId();
	static int getMusicId();
	static int getSoundId();
	static int getParticlesId();
	static int getTerrainId();

	static MouseClick getLastMouseClick();

	static int width();
	static int height();

	//utils
	static void init(char* title,int w,int h,int syncRate=60);
	static void setResolution(int w,int h);
	static bool loop();
	static void refresh();

	static void setBackdropColor(int r,int g,int b);
	static void setDir(char* dir);
};