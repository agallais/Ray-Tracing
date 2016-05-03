#pragma once
#include "Vector.h"
#include "Spheres.h"

class Ray
{
public:
	Vector direction;
	double x;
	double y;
	double z;
	


	Ray();
	~Ray();
	
	bool intersects(Spheres s, Vector* intersection);
};

