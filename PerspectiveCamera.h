#pragma once
#include "Camera.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Ray.h"
#include "Bitmap.h"
#include "SceneObject.h"
#include "Light.h"
#include "Logger.h"
#define INF 1* pow(10, sizeof(int) * 8)

#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <algorithm>
class PerspectiveCamera :
	public Camera
{
protected:
	Vector3 origin;
	Vector3 forward;
	Vector3 up;
	Vector3 right;
	double height, width;

public:
	PerspectiveCamera(Vector3 origin, Vector3 target, Vector3 upguide, double fov, double aspectRatio);
	virtual ~PerspectiveCamera();
	double CalculateShadow(Ray r, SceneObject* o);

	virtual void RayTrace(Bitmap& bmp, std::vector<SceneObject*> scene, std::vector<Light> lights);

	SceneObject* FindClosestObject(const Ray& ray, Vector3& hitPoint, RGBColor& hitColor, std::vector<SceneObject*> scene);

	double FindShadingMultiplier(Vector3& hitPoint, std::vector<Light> & lights,
		std::vector<SceneObject*> scene, SceneObject* closestObject);


	// Inherited via Camera
	virtual Ray CastRay(const Vector2& point) const override;

	// Inherited via Camera
	virtual std::string GetType() override;
};

