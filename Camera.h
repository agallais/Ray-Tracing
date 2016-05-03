#pragma once
#include "Vector.h"
class Camera
{
public:
	Vector eye;
	Vector target;
	Vector up;
	double width;
	double height;

	Camera();
	~Camera();


};

