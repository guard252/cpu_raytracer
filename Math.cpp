#include "Math.h"
#include <iostream>
bool Quadratic(double a, double b, double c, double & x1, double & x2)
{
	double D = b * b - 4 * a * c;
	if (D < 0) return false;

	x1 = (-b + sqrt(D)) / (2 * a);
	x2 = (-b - sqrt(D)) / (2 * a);
	

	return true;

}
