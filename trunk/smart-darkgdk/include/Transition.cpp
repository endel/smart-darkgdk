#include "Transition.h"

//------------------------------------------------
//			   STATIC CONST VARIABLES
//------------------------------------------------

float Transition::Linear[]			= {0,0,0,0,1};

float Transition::InQuadratic[]		= {0,0,0,1,0};
float Transition::InCubic[]			= {0,0,1,0,0};
float Transition::InQuartic[]		= {0,1,0,0,0};
float Transition::InQuintic[]		= {1,0,0,0,0};

float Transition::OutQuadratic[]	= {0,0,0,-1,2};
float Transition::OutCubic[]		= {0,0,1,-3,3};
float Transition::OutQuartic[]		= {0,-1,4,-6,4};
float Transition::OutQuintic[]		= {1,-5,10,-10,5};

float Transition::InOutCubic[]		= {0,0,-2,3,0};
float Transition::InOutQuintic[]	= {6,-15,10,0,0};

float Transition::OutInCubic[]		= {0,0,4,-6,3};
float Transition::OutInQuartic[]	= {0,0,4,-6,3};

float Transition::OutBackQuartic[]	= {0,-2,10,-15,8};
float Transition::OutBackCubic[]	= {0,0,4,-9,6};

float Transition::BackInQuartic[]	= {0,2,2,-3,0};
float Transition::BackInCubic[]		= {0,0,4,-3,0};

float Transition::OutElasticBig[]	= {56,-175,200,-100,20};
float Transition::OutElasticSmall[]	= {33,-106,126,-67,15};

float Transition::InElasticSmall[]	= {33,-59,32,-5,0};
float Transition::InElasticBig[]	= {56,-105,60,-10,0};