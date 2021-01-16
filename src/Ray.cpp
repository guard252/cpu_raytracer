#include "Ray.h"
#include "SceneObject.h"
#include <stdint.h>


Ray::Ray()
{

}


Ray::~Ray()
{

}

bool Ray::Hit(SceneObject * o, Vector3 & point1)
{
	if (o->Intersects(*this, point1))
	{
		return true;
	}
	return false;
}
