#include "PerspectiveCamera.h"
#include "Sphere.h"
#include "Plane.h"
#define PI 3.141592

PerspectiveCamera::PerspectiveCamera(Vector3 origin, Vector3 target, Vector3 upguide, double fov, double aspectRatio) :
	origin{ origin }
{
	forward = (target - origin).Normalize();
	right = forward.Cross(upguide).Normalize();
	up = right.Cross(forward);

	height = tan(fov);
	width = aspectRatio * height;

}

PerspectiveCamera::~PerspectiveCamera()
{
}

//Get the shading coefficient depending on the angle between 
// the object and a ray casted towards it
double PerspectiveCamera::CalculateShadow(Ray r, SceneObject* o)
{
	Vector3 hitPoint;
	if (o->Intersects(r, hitPoint) && o != nullptr)
	{
		return std::max(0.0, -r.Direction().Cos(o->GetNormal(hitPoint)));
	}
	return 0;
}

void PerspectiveCamera::RayTrace(Bitmap& bmp, std::vector<SceneObject*> scene, std::vector<Light> lights)
{
	for (int x = 0; x < bmp.Width(); x++)
	{
		for (int y = 0; y < bmp.Height(); y++)
		{
			// Translation from picture coordinates to world 
			Vector2 picCoord(((2.0*x) / bmp.Width() - 1.0) / ((double)bmp.Height() / bmp.Width()),
							((-2.0*y) / bmp.Height() + 1.0) / ((double)bmp.Height() / bmp.Width()));

			Ray ray = CastRay(Vector2(picCoord.X(), picCoord.Y()));
			Vector3 hitPoint;
			RGBColor hitColor{ 255, 255, 255 };
			SceneObject* closestObject = FindClosestObject(ray, hitPoint, hitColor, scene);
			double shadingMeasure = FindShadingMultiplier(hitPoint, lights, scene, closestObject);

			bmp.GetPixel(x, y) = hitColor * shadingMeasure;
		}
	}
}

//Get the closest element to the camera, which intersects with 
// the casted ray
SceneObject * PerspectiveCamera::FindClosestObject(const Ray & ray, Vector3 & hitPoint, RGBColor & hitColor, std::vector<SceneObject*> scene)
{
	SceneObject* result{ nullptr };
	double lenght = DBL_MAX;
	Vector3 curHitPoint;
	for (auto& a : scene)
	{
		if (a->Intersects(ray, curHitPoint))
		{
			if ((curHitPoint - origin).Magnitude() < lenght)
			{
				lenght = (curHitPoint - origin).Magnitude();
				hitPoint = curHitPoint;
				if (a->GetColor() != nullptr)
					hitColor = *(a->GetColor());
				result = a;
			}
		}
	}
	return result;
}

//Whole shading  process
double PerspectiveCamera::FindShadingMultiplier(Vector3 & hitPoint, std::vector<Light> & lights,
	std::vector<SceneObject*> scene, SceneObject* closestObject)
{
	double shadingMeasure = 0;

	for (auto light : lights)
	{
		Vector3 shadowHit;
		Ray ray = Ray(hitPoint, light.Position() - hitPoint);
		double lenght = DBL_MAX;
		double thisShadingMeasure = 1;
		for (auto a : scene)
		{
			bool isShaded = a->Intersects(ray, shadowHit);
			if (isShaded)
			{
				double curLength = (light.Position() - shadowHit).Magnitude();
				if (curLength < lenght)
				{
					lenght = curLength;
					if ((shadowHit - hitPoint).Magnitude() < (light.Position() - hitPoint).Magnitude() &&
						shadowHit != hitPoint)
					{
						thisShadingMeasure = 0;
						break;
					}
				}
			}

		}
		if (thisShadingMeasure > 1e-8)
		{
			shadingMeasure += 1.0 / lights.size() * CalculateShadow(Ray(light.Position(), -ray.Direction()), closestObject);
		}
	}
	
	return shadingMeasure;
}

Ray PerspectiveCamera::CastRay(const Vector2& point) const
{
	Vector3 direction = forward + right * point.X() * width + up * point.Y() * height;
	Ray res{ origin, direction.Normalize() };
	return res;
}

std::string PerspectiveCamera::GetType()
{
	return std::string("PerspectiveCamera");
}
