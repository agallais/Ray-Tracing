#include "Vector.h"



Vector::Vector()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}
Vector::Vector(double xx, double yy, double zz)
{
	x = xx;
	y = yy;
	z = zz;
}

Vector::~Vector()
{

}

Vector Vector::multiply(double l)
{
	Vector result =  Vector((this->x)*l, (this->y)*l, (this->z)*l);
		return result;
}

Vector Vector::add(Vector b)
{
	Vector *result = new Vector(x + b.x,y+b.y,z+b.z);
	return *result;
}

Vector Vector::soustract(Vector b)
{
	return Vector(x-b.x,y-b.y,z-b.z);
}

double Vector::scalaire(Vector b)
{
	return (x*b.x+y*b.y+z*b.z);
}

void Vector::normalize()
{
	
	double n = x*x + y*y + z*z;
	n = sqrt(n);
	assert(!n==0);
	x = x / n;
	y = y / n;
	z = z / n;


}
