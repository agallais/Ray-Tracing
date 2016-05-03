#include "Couleur.h"
#include "camera.h"
#include "Vector.h"
#include "Color.h"
#include "Light.h"
#include <set>
#include "Scene.h"
#include "Ray.h"
#include <iostream>
using namespace std;


Couleur::Couleur()
{
}


Couleur::~Couleur()
{
}


Color Couleur::couleur(Scene scene, double x, double y, double z, Light light, Camera cam)
{	// x,y,z désignent le point de l'espace qu'on vise
	//light gère l'éclairage de la scène
	//camera la camera pour l'instant la seule chose qui nous interesse dans la camera c'est la position de l'oeil
	//On va se faire une première version avec les notations de l'énoncé

	Vector *L, *N, *V, *R, *Point;
	Point = new Vector();
	V = new Vector(cam.eye.x - x, cam.eye.y - y, cam.eye.z - z);
	Ray *ray = new Ray();// le rayon Ray sert à utiliser la méthode intersectsp->
	ray->direction = *V;
	ray->x = cam.eye.x;
	ray->y = cam.eye.y;
	ray->z = cam.eye.z;
	Color *result = new Color();
	for (set<Spheres>::iterator p = scene.collection.begin(); p != scene.collection.end(); ++p)
	{//on dispose maintenant d'un pointeur p sur chacun des éléments de la scene
		//on se place dans un cas simple une seule shère sur notre route,
		// sinon, il faut gérer un truc plus compliqué et regarder quel est le point le plus proche
		bool calcul = ray->intersects(*p, Point);
		if (calcul) {//on fait l'hypothèse simplificatrice qu'il n'y a qu'un seul éclairage à considérer.
			L = new Vector(light.x - Point->x, light.y - Point->y, light.z - Point->z);//Bonne direction
			L->normalize();
			*N = Point->soustract(p->centre);
			N->normalize();
			Vector *Temp = new Vector(0, 0, 0);
			*R = Temp->add(N->multiply(N->scalaire(*L)));//composante normale
			*Temp = Vector(0, 0, 0);
			*Temp = L->soustract(*R);
			*Temp = Temp->multiply(-1.0);
			*R = R->add(*Temp);//composante tangentielle
			//Là on a un problème:
			double intensity = (L->scalaire(*N)) + (R->scalaire(*V));

			result->intensity(intensity);
		}
	}

	return *result;
};