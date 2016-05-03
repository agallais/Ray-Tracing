#include "Ray.h"
#include "Vector.h"


Ray::Ray()
{
}


Ray::~Ray()
{
}

bool Ray::intersects(Spheres s, Vector* intersection)
{
	bool result = true;
	double temp;
	temp = direction.scalaire(Vector(x - s.x, y - s.y, z - s.z));
	double temp2;
	temp2 = direction.scalaire(direction);
	Vector *temp3 = new Vector(x - s.x, y - s.y, z - s.z);
	result =temp3->scalaire(*temp3)-(temp*temp)/temp2 < (s.r*s.r);
	return result;
}
