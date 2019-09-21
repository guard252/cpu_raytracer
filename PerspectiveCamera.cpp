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

void PerspectiveCamera::RayTrace(Bitmap& bmp, std::vector<SceneObject*> scene, Light light)
{
	for (int x = 0; x < bmp.Width(); x++)
	{
		for (int y = 0; y < bmp.Height(); y++)
		{
			// Translation from picture coordinates to world 

			Vector2 picCoord(((2.0*x) / bmp.Width() - 1.0) / ((double)bmp.Height()/bmp.Width()), ((-2.0*y) / bmp.Height() + 1.0) / ((double)bmp.Height() / bmp.Width()));

			Ray ray = CastRay(Vector2(picCoord.X(), picCoord.Y()));
			Vector3 curHitPoint;
			Vector3 hitPoint;
			RGBColor hitColor{ 255, 255, 255 };
			bool hits = false;

			double lenght = INF;
			for (auto a : scene)
			{
				if (a->Intersects(ray, curHitPoint))
				{
					hits = true;
					if ((curHitPoint - origin).Magnitude() < lenght)
					{
						lenght = (curHitPoint - origin).Magnitude();
						hitPoint = curHitPoint;
						if (a->GetColor() != nullptr)
							hitColor = *(a->GetColor());
					}
				}
			}

			bool l = true;

			if (hits)
			{
				Vector3 shadowHit;
				ray = Ray(hitPoint, light.Position() - hitPoint);
				double length = INF;
				for (auto a : scene)
				{
					bool isShaded = a->Intersects(ray, shadowHit);
					if (isShaded)
					{
						double curLength = (light.Position() - shadowHit).Magnitude();
						if (curLength < lenght)
						{
							length = curLength;

							if ((shadowHit - hitPoint).Magnitude() < (light.Position() - hitPoint).Magnitude() &&
								shadowHit != hitPoint)
							{
								l = false;
								break;
							}
							else l = true;
						}
					}
					else l = true;
				}
			}
			try {
			//	if(x == 1080 && y == 320)
				bmp.GetPixel(x, y) = hitColor * l;
			}
			catch (std::exception& e)
			{
				//goto END;//std::cout << e.what();
			}

		}
	}
//END:;
}

Ray PerspectiveCamera::CastRay(const Vector2& point) const
{
	Vector3 direction = forward + right * point.X() * width + up * point.Y() * height;
	Ray res{ origin, direction.Normalize() };
	return res;
}
