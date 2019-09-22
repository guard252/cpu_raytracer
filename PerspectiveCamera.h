#pragma once
#include "Camera.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Ray.h"
#include "Bitmap.h"
#include "SceneObject.h"
#include "Light.h"

#define INF 1e10

#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
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
	virtual void RayTrace(Bitmap& bmp, std::vector<SceneObject*> scene, Light l);
	// Inherited via Camera
	virtual Ray CastRay(const Vector2& point) const override;
};

