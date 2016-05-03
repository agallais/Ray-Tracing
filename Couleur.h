#pragma once
#include "Couleur.h"
#include "camera.h"
#include "Vector.h"
#include "Color.h"
#include "Light.h"
#include <set>
#include "Scene.h"
#include "Ray.h"
using namespace std;

class Couleur
{
public:
	Couleur();
	~Couleur();


	Color couleur(Scene scene, double x, double y, double z, Light light, Camera cam);
};

