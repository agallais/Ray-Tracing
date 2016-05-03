#pragma once
#include<assert.h>
#include<math.h>
class Vector
{
public:
	double x;
	double y;
	double z;

	Vector();
	Vector(double xx, double yy, double zz);
	~Vector();

	Vector multiply(double l);
	Vector add(Vector b);
	Vector soustract(Vector b);
	double scalaire(Vector b);
	void normalize();//normalise le vecteur
};

