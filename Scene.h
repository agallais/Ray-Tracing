#pragma once
#include"Spheres.h"
#include "stdafx.h"
#include <set>
using namespace std;

class Scene
{
public:
	//is a set of spheres :(
	set<Spheres> collection;

	Scene();
	~Scene();
	

};

