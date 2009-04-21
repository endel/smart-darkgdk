#pragma once

class Transition
{
public:
	//-->STATIC CONST VARIABLES
	
	static float Linear[];

	static float InQuadratic[];
	static float InCubic[];
	static float InQuartic[];
	static float InQuintic[];

	static float OutQuadratic[];
	static float OutCubic[];
	static float OutQuartic[];
	static float OutQuintic[];

	static float InOutCubic[];
	static float InOutQuintic[];

	static float OutInCubic[];
	static float OutInQuartic[];

	static float OutBackQuartic[];
	static float OutBackCubic[];

	static float BackInQuartic[];
	static float BackInCubic[];

	static float OutElasticBig[];
	static float OutElasticSmall[];

	static float InElasticSmall[];
	static float InElasticBig[];
};
