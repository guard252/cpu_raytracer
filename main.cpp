#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Bitmap.h"
#include "Ray.h"
#include "Sphere.h"
#include "Plane.h"
#include "PerspectiveCamera.h"
#include "Light.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;
const double PI = 3.14159265358979323846;
int main()
{
	Bitmap bmp(WIDTH, HEIGHT, 24, RGBColor{ 255, 255, 255 });
	//Plane a( Vector3(0, 0, 0), Vector3(1, 0, 0) );
	RGBColor c{ 255, 255, 0 };
	RGBColor d{ 0, 255, 255 };
	RGBColor e{ 255, 0,  255 };
	RGBColor f{ 0, 0,  255 };


	Light light(Vector3(0,0, 3));
	Sphere b(Vector3(0, 2, 1), 2, &c);
	Plane floor{ Vector3(0,-3,0), Vector3(0, 1, 0),  &d };
	Plane backWall{ Vector3(0,0,0), Vector3(0, 0, 1),  &e };
	Plane leftWall{ Vector3(-3,0,0), Vector3(1, 0, 0),  &f };
	std::vector<SceneObject*> scene;
	scene.push_back(&b);
	scene.push_back(&floor);
	scene.push_back(&backWall);
	scene.push_back(&leftWall);

	PerspectiveCamera camera(Vector3(0, 0, 10), Vector3(0, 0, 0), Vector3(0, 1, 0), PI / 4, (double)HEIGHT / (double)WIDTH);
	camera.RayTrace(bmp, scene, light);
	bmp.Write("Copy.bmp");


}
