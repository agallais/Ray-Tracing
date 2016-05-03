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
{	// x,y,z d�signent le point de l'espace qu'on vise
	//light g�re l'�clairage de la sc�ne
	//camera la camera pour l'instant la seule chose qui nous interesse dans la camera c'est la position de l'oeil
	//On va se faire une premi�re version avec les notations de l'�nonc�

	Vector *L, *N, *V, *R, *Point;
	Point = new Vector();
	V = new Vector(cam.eye.x - x, cam.eye.y - y, cam.eye.z - z);
	Ray *ray = new Ray();// le rayon Ray sert � utiliser la m�thode intersectsp->
	ray->direction = *V;
	ray->x = cam.eye.x;
	ray->y = cam.eye.y;
	ray->z = cam.eye.z;
	Color *result = new Color();
	for (set<Spheres>::iterator p = scene.collection.begin(); p != scene.collection.end(); ++p)
	{//on dispose maintenant d'un pointeur p sur chacun des �l�ments de la scene
		//on se place dans un cas simple une seule sh�re sur notre route,
		// sinon, il faut g�rer un truc plus compliqu� et regarder quel est le point le plus proche
		bool calcul = ray->intersects(*p, Point);
		if (calcul) {//on fait l'hypoth�se simplificatrice qu'il n'y a qu'un seul �clairage � consid�rer.
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
			//L� on a un probl�me:
			double intensity = (L->scalaire(*N)) + (R->scalaire(*V));

			result->intensity(intensity);
		}
	}

	return *result;
};